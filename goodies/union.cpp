#include <iostream>
#include <string>

struct A 
{
	// Constructor
	A() 
	{
		std::cout << __func__ << std::endl;
	}
	// Destructor
	~A() 
	{
		std::cout << __func__ << std::endl;
	}
	// Copy constructor
	A(const A& other) 
	{
		std::cout << __func__ << std::endl;
	}
	// Move constructor
	A(A&& other) noexcept
	{
		std::cout << __func__ << std::endl;
	}
	// Copy assignment operator
	A& operator=(const A& other) 
	{
		std::cout << __func__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}
	// Move assignment operator
	A& operator=(A&& other) noexcept 
	{
		std::cout << __func__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}
};

struct B {

	B() {
		std::cout << __func__ << std::endl;

	}
	~B() {
		std::cout << __func__ << std::endl;

	}

	B(const B& other) {
		std::cout << __func__ << std::endl ;
	}

	B(B&& other) noexcept {
		std::cout << __func__ << std::endl ;
	}

	B& operator=(const B& other) {
		std::cout << __func__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}

	B& operator=(B&& other) noexcept {
		std::cout << __func__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}
	virtual void Foo(){}
	
};

union UDT {
	A a ;
	B b ;
	std::string s ;
	// We must provide constructor
	UDT() 
	{
		
	}
	// We must provide destructor
	~UDT() 
	{
		
	}
};

void my_union()
{
	using namespace std::string_literals ;
	UDT udt;

	//udt.s = "Hello world";

	new(&udt.s) std::string{"Hello world"} ;

	new (&udt.a) A{} ;
	udt.a.~A() ;
	
}