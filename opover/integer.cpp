#include "integer.hpp"
#include <iostream>


// TypeConversion
Integer::operator int()
{
	return *m_pInt;
}

Integer::Integer() 
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) 
{
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) 
{
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) 
{
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const 
{
	return *m_pInt;
}

void Integer::SetValue(int value) 
{
	*m_pInt = value;
}

Integer::~Integer() 
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

// pre ++ operator, returns reference lvalue
Integer & Integer::operator++() 
{
	++(*m_pInt);
	return *this; //return by ref
	// TODO: insert return statement here
}
// post ++ operator, 
Integer  Integer::operator++(int) 
{	//return then increment
	Integer temp(*this);//copy ctor
	++(*m_pInt);
	return temp; //temporary, rvalue
}

bool Integer::operator==(const Integer & a) const 
{
	return *m_pInt == *a.m_pInt;
}

// Copy and move semantics

// Member function. Receives reference. Return reference.
// Copy semantic
Integer & Integer::operator=(const Integer & a) 
{
	if (this != &a) 
	{ // Check self assignment
		delete m_pInt;
		m_pInt = new int(*(a.m_pInt) );  // <<<<---- new object. Copy semantic
	}
	return *this;
}
// Member function. Receives R value, use move semantics.
// Check if is not self. 
Integer & Integer::operator=(Integer && a)  // RVALUE argument
{	
	if (this != &a) 
	{ // Check self assignment
		delete m_pInt;
		m_pInt = a.m_pInt; // <<<<--- Move semantic	
		a.m_pInt = nullptr;
	}
	return *this;
}


// Member  function. + operator receiving reference,
// treated as const, only read method
Integer Integer::operator+(const Integer & a) const 
{
	Integer temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}

// Member function. Function operator. Any num of args
void Integer::operator()() {
	std::cout << *m_pInt << std::endl; 
}

// Global + operator receiving value and reference, treated as const
Integer operator +(int x, const Integer &y) 
{
	Integer temp;
	temp.SetValue(x + y.GetValue());
	return temp;
}

// Global function. out by ref, not constant.
// Return out by reference, is no local
std::ostream & operator <<(std::ostream & out, const Integer &a) 
{
	// How to access private functions?
	out << a.GetValue();
	return out;
}

std::istream & operator >> (std::istream &input, Integer &a) 
{
	// How to access private functions?
	int x;
	input >> x;
	a.SetValue(x);
	return input;
}
