#include <iostream>
#include "account.h"
// coupling
#include "checking.h" 

// Base class pointer can point to any of its child class objects

void Transact(Account * pAccount) 
{
	std::cout << "Transaction started" << std::endl; 
	std::cout << "Initial balance:" << pAccount->GetBalance() << std::endl;

	// By default the compiler will try to call the base class methods!
	pAccount->Deposit(100);
	pAccount->AccumulateInterest();

	if ( typeid(*pAccount) == typeid(Checking) ) 
	{ // Verify casting with typeid
		// Upcasting
		Checking *pChecking = static_cast<Checking*>(pAccount);
		std::cout << "Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
	}

	// Best avoid dynamic cast, because is slower
	Checking *pChecking = dynamic_cast<Checking*>(pAccount);
	if (pChecking != nullptr) 
	{
		std::cout << "Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
	}

	// By default the compiler will try to call the base class methods!
	pAccount->Withdraw(170);
	std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
	std::cout << "Final balance:" << pAccount->GetBalance() << std::endl;
}
