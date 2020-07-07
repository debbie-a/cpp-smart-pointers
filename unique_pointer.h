#ifndef __UNIQUE_Ptr_H__
#define __UNIQUE_Ptr_H__

#include "smart_pointer.h"
#include "non_copyable.h"

template<typename T>
class UniquePtr : public SmartPtr<T>, private NonCopyable
{
public:
	UniquePtr(T *ptr = nullptr);
	
};

template<typename T>
inline UniquePtr<T>::UniquePtr(T *ptr):SmartPtr<T>(ptr)
{

}

template<typename T>
bool operator==(const UniquePtr<T>& uniquePtr1, const UniquePtr<T>& uniquePtr2)
{
	return uniquePtr1.getPtr() == uniquePtr2.getPtr();
}

template<typename T>
bool operator!=(const UniquePtr<T>& uniquePtr1, const UniquePtr<T>& uniquePtr2)
{
	return !(uniquePtr1 == uniquePtr2);
}


template<typename T>
std::ostream& operator<<(std::ostream& cout, const UniquePtr<T>& uniquePtr) 
{ 
       	cout << uniquePtr.getPtr();
	return cout;
}

#endif /*__UNIQUE_Ptr_H__*/


