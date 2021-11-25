#include "integer.hpp"
#include <iostream>

Integer Add(const Integer &a, const Integer &b)
{
	Integer temp ; //<<---
	temp.SetValue(a.GetValue() + b.GetValue()) ;
	return temp ;
}

/*
Rule of 0
If a class has no ownership semantics:
- Don't implement anyone.
- If you provide custom implementation of any,
default move operation is deleted.
- If you provide custom move, default copy is deleted.
- You can force default operations, will be considered custom.

Rule of 5
If a class has ownership semantics, provide 
- a default constructor: X()
- a copy constructor: X(const X&)
- a copy assignment: operator=(const X&)
- a move constructor: X(X&&)
- a move assignment: operator=(X&&)
- a destructor: ~X()
*/

//Elide: ommit or leave out a vowel or syllable.
//Elision: act of omission.

int main() 
{
	Integer a(1);
	Integer b(3);
	
	std::cout << "--- Elision test" << std::endl;

	Integer c = 3;

	std::cout << "--- Move test" << std::endl;

	a.SetValue( Add(a,b).GetValue() );
	
	std::cout << "--- Move test" << std::endl;

	auto m{static_cast<Integer&&>(a)}; // Force move semantic
	auto v{  std::move(a) }; // Force move semantic
	// std::move appluied to lvalue.
	// Performs typecast as rvalue 
	//Free resource after using object.
	// No longer valid in here after std::move.



	std::cout << "--- End test" << std::endl;

	return 0;
}

/*
Integer(int) 1
Integer(int) 3
Integer(int &&)
~Integer()
--- Elision test
Integer(int) 3
Integer(int &&)
~Integer()
--- Move test
Integer()
Integer(int &&)
~Integer()
~Integer()
--- End test
~Integer()
~Integer()
~Integer()
*/