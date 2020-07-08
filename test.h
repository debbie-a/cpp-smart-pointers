#ifndef __TEST_H__
#define __TEST_H__


class A
{

public:
	int getA() const {return a;}

private:
	int a;
};

class B: public A
{

public:
	int getB() const {return b;}

private:
	int b;
	
};


void testSmartPointer();
void testUniquePointer();
void testSharedPointer();

#endif /*__TEST_H__*/
