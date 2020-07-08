#ifndef __UNIQUE_Ptr_H__
#define __UNIQUE_Ptr_H__

#include "smart_pointer.h"
#include "non_copyable.h"

template<typename T>
class UniquePtr : public SmartPtr<T>, private NonCopyable
{
public:
	UniquePtr(T *ptr);
};

template<typename T>
inline UniquePtr<T>::UniquePtr(T *ptr):SmartPtr<T>(ptr)
{

}

template<typename T>
inline bool operator==(const UniquePtr<T>& uniquePtr1, const UniquePtr<T>& uniquePtr2)
{
	return uniquePtr1.getPtr() == uniquePtr2.getPtr();
}

template<typename T>
inline bool operator!=(const UniquePtr<T>& uniquePtr1, const UniquePtr<T>& uniquePtr2)
{
	return !(uniquePtr1 == uniquePtr2);
}


template<typename T>
inline std::ostream& operator<<(std::ostream& cout, const UniquePtr<T>& uniquePtr) 
{ 
       	cout << uniquePtr.getPtr();
	return cout;
}

#endif /*__UNIQUE_Ptr_H__*/


