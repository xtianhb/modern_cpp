#include "integer.hpp"
#include <iostream>
#include <memory>

/*
RULES
Opeators conserve associativity, precesence, & count.
Opeartor functions should be non static
One argument should be user defined type
One argument sohould be user defined type
global overload is first operand primitive tyoe.

Not allowed: . ?:  .* sizeof hash casting
Cannot define new operators
Overload for conventional behaviour
.*/


class IntPtr 
{
	Integer *m_p;
public:
	IntPtr(Integer *p) :m_p(p) 
	{

	}
	~IntPtr() 
	{
		delete m_p;
	}
	// Overload arrow op. 
	Integer *operator ->() 
	{
		return m_p;
	}
	Integer & operator *() 
	{
		return *m_p;
	}
};

void Process1(std::unique_ptr<Integer> ptr) 
{
	std::cout << ptr->GetValue() << std::endl;
}

void Process2(std::shared_ptr<Integer> ptr) 
{
	std::cout << ptr->GetValue() << std::endl;
}

void CreateInteger() 
{
	// Smart pointers
	// They are used when you don't want to share the resource
	// Can't copy the pointer, but yes move it.
	// NO copy semantics. Ok move semantics.
	std::unique_ptr<Integer> p1(new Integer);
	//Process(p); // Not allowed.
	// auto p2(p); // Not allowed,deleted function copy constructor.
	Process1(std::move(p1));// p no longer holds the resource.
	
	
	// Shared pointers
	// You want to sare the resource with other parts of the code.
	// On each copy the reference count ++
	// On zero, frees the resource.
	std::shared_ptr<Integer> p2 (new Integer);
	Process2(p2);// p no longer holds the resource.
	(*p2).SetValue(3);

	IntPtr p3 = new Integer;
	(*p3).SetValue(3);
	std::cout << p3->GetValue() << std::endl; 

	// C++ encourage use smart pointers -> Prevent memory leaks
}

void Process(Integer val) 
{
	std::cout << val << std::endl;
}

void TypeConv(void);
void TypeConv2(void);
void TypeConv3(void);

int main() 
{

	Integer a(3), b(3);
	Integer Sum;

	// Operator +

	a = a + 5;
	Sum = 5 + a; //Doesn't work

	std::cout << "Process()" << std::endl;

	Process(std::move(a));

	std::cout << "CreateInteger()" << std::endl;

	CreateInteger();
	
	std::cout << "End" << std::endl;

	TypeConv();
	TypeConv2();
	TypeConv3();
	return 0;
}

void TypeConv()
{ // primitive - primitive
	std::cout << "typeconv" << std::endl;

	int a=5, b=2, c=3;
	float f=1.0, g=4.0;

	f = (float) a/b; // c style cast. Don't use!!
	f = static_cast<float>(a/b); 

	char *p;
	p = (char *)&a;
	//p = static_cast<char *>(&a); // Not allowed
	p = reinterpret_cast<char *>(&a); // Not allowed

	std::cout << f << std::endl;
	std::cout << *p << std::endl;
	std::cout << "//typeconv" << std::endl;

}

//void Print(Integer a) also works
void Print(const Integer &a)
{
	std::cout << a << std::endl;
}
void TypeConv2()
{
	// primitive - userdef
	std::cout << "typeconv2" << std::endl;

	Integer a1 {5}; // Parametrized constructor, initiliazes object.
	Integer a2 = 5; // Searchs for the proper parametrizer constructor. 

	Print(a1); // Coverts primitive into us def type param coctor.

	a1 = 4; // We don't have = operator for int. But we have for Integer type.
	// rvalue. Will use move assignmet operator, and there call the param cctor.

	// You can use explicit keyword to avoid using typeconversion in operators and semantics.

	std::cout << "//typeconv2" << std::endl;

	return;
}

class Product
{
	Integer m_Id; //<--default is called
	int x;
public:
	// User def ctor
	// member initiliazor list
	Product(const Integer &id):m_Id(id), x(id.GetValue())
	{
		std::cout << "Product(const Integer &id)" << std::endl;
		//m_Id = id; // Assignment operator. no longer required
	}
	~Product()
	{
		std::cout << "~Product()" << std::endl;
	}
};
void TypeConv3()
{
	// userdef - userdef

	std::cout << "/////typeconv3" << std::endl;
	//Integer a1 {5};
	//int x = static_cast<int>(a1);
	Product p(5); // 5-> Integer object
	std::cout << "typeconv3//////" << std::endl;
	return;
}