#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__

#include <iostream>

template<typename T>
class SmartPtr
{
public:
	explicit SmartPtr(T *ptr = nullptr);
	~SmartPtr();

	T* operator->();
    	T& operator*();
	
	T* getPtr() const;
	
private:
	T *m_ptr;
};


template<typename T>
inline SmartPtr<T>::SmartPtr(T *ptr):m_ptr(ptr)
{
}

template<typename T>
inline SmartPtr<T>::~SmartPtr()
{
	delete m_ptr;
}

template<typename T>
inline T* SmartPtr<T>::operator->()
{
	return m_ptr;
}

template<typename T>
inline T& SmartPtr<T>::operator*()
{
	return *m_ptr;
}

template<typename T>
inline T* SmartPtr<T>::getPtr() const
{
	return m_ptr;
}

template<typename T>
bool operator==(const SmartPtr<T>& smartPtr1, const SmartPtr<T>& smartPtr2)
{
	return smartPtr1.getPtr() == smartPtr2.getPtr();
}

template<typename T>
bool operator!=(const SmartPtr<T>& smartPtr1, const SmartPtr<T>& smartPtr2)
{
	return !(smartPtr1 == smartPtr2);
}

template<typename T>
std::ostream& operator<<(std::ostream& cout, const SmartPtr<T>& smartPtr) 
{ 
       	cout << smartPtr.getPtr();
	return cout;
}

#endif /*__SMART_POINTER_H__*/
