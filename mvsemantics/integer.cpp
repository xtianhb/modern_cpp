#include "integer.hpp"
#include <iostream>

Integer::Integer() 

{	//Default constructor
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) 
{
	//Parameterized constructor
	std::cout << "Integer(int) " << value << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) 
{
	//Copy constructor
	std::cout << "Integer(const Integer &)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

#if MOVE_SEM==1
Integer::Integer(Integer && obj) 
{
	//Move constructor
	std::cout << "Integer(int &&)" << std::endl;
	m_pInt = obj.m_pInt; // Shallow copy. Efficient.
	obj.m_pInt = nullptr; // Safe
}
#endif

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






