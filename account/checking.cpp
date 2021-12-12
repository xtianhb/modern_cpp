#include "checking.h"
#include <iostream>


Checking::Checking(const std::string &name, float balance, float minbalance):
m_MinimumBalance(minbalance), Account(name, balance)
{

}


Checking::~Checking() 
{
	std::cout << "~Checking()" << std::endl; 
}


void Checking::Withdraw(float amount) 
{
	if ((m_Balance - amount) > m_MinimumBalance) 
	{	// Scope is important, otherwise becomes recursive
		Account::Withdraw(amount); //public from base
	}
	else 
	{
		std::cout << "Invalid amount" << std::endl; 
	}
}

float Checking::GetMinimumBalance() const 
{
	return m_MinimumBalance;
}
