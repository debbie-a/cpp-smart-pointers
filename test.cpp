#include "test.h"
#include "smart_pointer.h"
#include "unique_pointer.h"
#include "shared_pointer.h"

static const char *Bool[] = {"false", "true"};

void testSmartPointer()
{
	std::cout << "--- Testing Smart pointers ---" << std::endl;
	SmartPtr<char> ptr1(new char);
	*ptr1 = 'D';
	SmartPtr<char> ptr2(new char);
	*ptr2 = 'A';
	std::cout << ptr1 << std::endl; 
	std::cout << ptr2 << std::endl; 
	ptr1 = ptr2;
	std::cout << ptr1 << std::endl; 
	std::cout << ptr2 << std::endl; 
	std::cout << Bool[ptr1 == ptr2] << std::endl;
	std::cout << std::endl;
}

void testUniquePointer()
{
	std::cout << "--- Testing Unique pointers ---" << std::endl;
	UniquePtr<int> ptr1(new int(8));
	*ptr1 = 100;
	UniquePtr<int> ptr2(new int);
	*ptr2 = 99;
	std::cout << ptr1 << std::endl; 
	std::cout << ptr2 << std::endl; 
	//ptr1 = ptr2; does not compile!
	std::cout << Bool[ptr1 == ptr2] << std::endl;
	std::cout << std::endl;
	
}

void testSharedPointer()
{
	std::cout << "--- Testing Shared pointers ---" << std::endl; 
	SharedPtr<int> ptr1(new int);
	*ptr1 = 100;
	std::cout << ptr1.getNumCopies() << std::endl; 
    	std:: cout << *ptr1 << std::endl; 
    	{
		SharedPtr<int> ptr2 = ptr1; 
		std::cout << ptr1 << std::endl; 
		std::cout << ptr2 << std::endl;
		std::cout << ptr1.getNumCopies() << std::endl;
		std::cout << ptr2.getNumCopies() << std::endl; 
	  
		{ 
		    	SharedPtr<int> ptr3(ptr2); 
			std::cout << ptr1 << std::endl; 
		   	std::cout << ptr2 << std::endl; 
		   	std::cout << ptr3 << std::endl;
			std::cout << ptr1.getNumCopies() << std::endl; 
			std::cout << ptr2.getNumCopies() << std::endl;
			std::cout << ptr3.getNumCopies() << std::endl;
			std::cout << Bool[ptr1 == ptr2] << std::endl;
			  
		} 
	  
		std::cout << ptr1.getNumCopies() << std::endl; 
		std::cout << ptr2.getNumCopies() << std::endl; 
	}  
}
