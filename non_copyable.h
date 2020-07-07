#ifndef __NON_COPYABLE_H
#define __NON_COPYABLE_H

class NonCopyable 
//class to prevent using copy-ctor and assignment operator by putting these funcs private and derivg private from this class
{
public:
	NonCopyable(){}
	~NonCopyable(){}

private:
	NonCopyable(const NonCopyable&);
	NonCopyable& operator=(const NonCopyable&);
};
#endif /*__NON_COPYABLE_H*/

