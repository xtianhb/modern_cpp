#pragma once
#include "account.h"

class Checking : public Account 
{
private:
	float m_MinimumBalance;

public:
	using Account::Account; // C++11 Uses constructors from base class
	Checking(const std::string &name, float balance, float minbalance);
	~Checking();
	void Withdraw(float amount)override;
	
	float GetMinimumBalance()const;
};

// Add override to tell the compiler to enforce a function will be overrided