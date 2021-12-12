#include <iostream>
#include "savings.h"
#include "checking.h"
#include "transaction.h"
#include <typeinfo>

int main()
{
	Account Acc("Bob", 1000);

	Checking Check("Joe", 100, 50);

	Savings Savs("Bill", 100, 0.05f);
	
	Transact(&Check);

	// Object slicing
	Account * pAcc = & Check; // This works only with pointers or refs.
	Account pAccSliced = Check; // Upcasting - Slicing
	Checking * pCheeck = static_cast<Checking*>(pAcc); // Downcast

	// typeid
	// Gets typeid of poly type during runtime
	//Account * pSavs = &Savs;
	//const std::type_info &ti = typeid(pSavs);
	//std::cout << ti.name() << std::endl;

	
    return 0;
}
 
