#pragma once
#include <string>

class Account 
{
	
private:
	std::string m_Name;
	int m_AccNo;
	static int s_ANGenerator;

protected: // We can access it from child
	float m_Balance;

public:
	Account(const std::string &name, float balance);

	// Base classes should always have virtual destructor
	virtual ~Account();

	const std::string GetName()const;
	float GetBalance()const;
	int GetAccountNo()const;

	// This functions override the base class methods
	// Polymorphic functions
	virtual void AccumulateInterest();
	virtual void Withdraw(float amount);
	virtual float GetInterestRate()const;

	void Deposit(float amount);
	
};

