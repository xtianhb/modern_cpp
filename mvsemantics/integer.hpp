#pragma once

#include <iostream>

#define MOVE_SEM	1

class Integer 
{

	int *m_pInt;

public:

	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);

	//Copy constructor
	Integer(const Integer &obj);

#if MOVE_SEM==1
	//Move constructor
	Integer(Integer &&obj);
#endif

	int GetValue()const;

	void SetValue(int value);

	~Integer();

};
