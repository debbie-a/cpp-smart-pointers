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
	Counter *m_numCopies;
};

template<typename T>
inline SharedPtr<T>::SharedPtr(T *ptr):m_ptr(ptr),m_numCopies(new Counter())
{
	if (ptr)
            (*m_numCopies)++;
	
}

template<typename T>
inline SharedPtr<T>::~SharedPtr()
{
	(*m_numCopies)--;
	if (0 == m_numCopies->getCounter())
	{
		delete m_ptr;
		delete m_numCopies;
	}

}

template<typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	m_ptr = other.m_ptr;
	m_numCopies = other.m_numCopies;
        (*m_numCopies)++;
}

template<typename T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if(this != other)
	{
		if (m_numCopies != nullptr)
		{
			(*m_numCopies)--;
			if (0 == m_numCopies->getCounter())
			{
				delete m_ptr;
				delete m_numCopies;
			}
		}
		m_ptr = other.m_ptr;
		m_numCopies = other.m_numCopies;
		(*m_numCopies)++;
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
	return m_numCopies != nullptr ? (m_numCopies->getCounter()) : 0;
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
