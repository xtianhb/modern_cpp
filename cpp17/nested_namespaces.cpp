#include <iostream>

namespace A
{
	namespace B
	{
		namespace C
		{

		}
	}
}
namespace A::B::C
{
	static void Foo()
	{
	
	}
}

int nested_namespaces()
{
	std::cout << "NESTED NAMESPACES" << std::endl; 
	A::B::C::Foo() ; // Fully qualifier name

	using A::B::C::Foo; // Using declaration
	Foo();

	using namespace A::B::C ;
	Foo();

	return 0;
}