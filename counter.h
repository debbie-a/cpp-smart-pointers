#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <iostream>
#include "non_copyable.h"

class Counter : private NonCopyable
{
	 friend std::ostream& operator<<(std::ostream& cout, const Counter& counter);
public:
	Counter(size_t startCounterFrom = 0);
    	
	void resetCounter();
  	size_t getCounter(); 
    	void operator++();
	void operator++(int);
    	void operator--(); 
    	void operator--(int);

private: 
    size_t m_counter;
 
}; 
 
inline Counter::Counter(size_t startCounterFrom):m_counter(startCounterFrom)
{
}

inline void Counter::resetCounter()
{ 
	m_counter = 0; 
} 

inline size_t Counter::getCounter()
{ 
        return m_counter;
}


inline void Counter::operator++() 
{ 
	m_counter++; 
} 
  
inline void Counter::operator++(int) 
{ 
	m_counter++; 
} 
  
inline void Counter::operator--() 
{ 
	m_counter--; 
} 

inline void Counter::operator--(int) 
{ 
	m_counter--; 
} 
  
inline std::ostream& operator<<(std::ostream& cout, const Counter& counter) 
{ 
	cout << counter.m_counter << std::endl; ; 
} 


#endif /*__COUNTER_H__*/
