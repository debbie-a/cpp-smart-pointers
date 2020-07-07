#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include <cstdlib>
#include <iostream>
#include "counter.h"

template<typename T>
class SharedPtr
{
public:
	explicit SharedPtr(T *ptr = nullptr);
	~SharedPtr();
	SharedPtr(const SharedPtr<T>& other);
	SharedPtr& operator=(const SharedPtr<T>& other);
	
	T* operator->();
    	T& operator*();


	T* getPtr() const;
	size_t getNumCopies() const;

private:
	T *m_ptr;
	Counter *m_num_copies;
};

template<typename T>
inline SharedPtr<T>::SharedPtr(T *ptr):m_ptr(ptr),m_num_copies(new Counter(9))
{
	std::cout << m_num_copies->getCounter();
	 if (ptr)
            (*m_num_copies)++;
}

template<typename T>
inline SharedPtr<T>::~SharedPtr()
{
	(*m_num_copies)--;
	if (0 == m_num_copies->getCounter())
	{
		delete m_ptr;
		delete m_num_copies;
	}

}

template<typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	m_ptr = other.m_ptr;
	m_num_copies = other.m_num_copies;
        (*m_num_copies)++;
}

template<typename T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if(this != other)
	{
		if (m_num_copies != nullptr)
		{
			(*m_num_copies)--;
			if (0 == m_num_copies->getCounter())
			{
				delete m_ptr;
			}
		}
		m_ptr = other.m_ptr;
		m_num_copies = other.m_num_copies;
		(*m_num_copies)++;
	}

	return *this;
}

template<typename T>
inline T* SharedPtr<T>::operator->()
{
	return m_ptr;
}

template<typename T>
inline T& SharedPtr<T>::operator*()
{
	return *m_ptr;
}

template<typename T>
inline T* SharedPtr<T>::getPtr() const
{
	return m_ptr;
}

template<typename T>
inline size_t SharedPtr<T>::getNumCopies() const
{
	return m_num_copies != nullptr ? (m_num_copies->getCounter()) : 0;
}

template<typename T>
bool operator==(const SharedPtr<T>& SharedPtr1, const SharedPtr<T>& SharedPtr2)
{
	return SharedPtr1.getPtr() == SharedPtr2.getPtr();
}

template<typename T>
bool operator!=(const SharedPtr<T>& SharedPtr1, const SharedPtr<T>& SharedPtr2)
{
	return !(SharedPtr1 == SharedPtr2);
}

template<typename T>
std::ostream& operator<<(std::ostream& cout, const SharedPtr<T>& sharedPtr) 
{ 
       	cout << sharedPtr.getPtr();
	return cout;
} 
  
#endif /*__SHARED_POINTER_H__*/
