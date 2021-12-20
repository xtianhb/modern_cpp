#include <iostream>
#include <integer.hpp>
#include <variadic.hpp>

//Works only for homogenous data types
template<typename T>
void Print1(std::initializer_list<T> args) 
{
	for (const auto &x : args) 
	{
		std::cout << x << " ";
	}
}

void Print()
{
	std::cout << std::endl;
}

//Template parameter pack
template<typename T, typename...Params>
//Function parameter pack
void Print(T &&a, Params && ... args) 
{
	// T s stops the recursion
	// Also the Print() function

	//std::cout << sizeof...(args) << std::endl;
	//std::cout << sizeof...(Params) << std::endl;

	std::cout << a ;
	if (sizeof...(args) != 0) 
	{
		std::cout << ", ";
	}

	Print(std::forward<Params>(args)...);
	//We can forward a function parameter pack
	//Print2(std::forward<Params>(args)...);

}


int variadic() 
{
	std::cout << "VARIADIC >>>" << std::endl;

	std::cout << "Same type of args:" << std::endl;
	Print1({ 1, 2, 3, 4 });
	//Print1({ 1, 2, 3, 4.5 }); ERROR: different type of args

	std::cout << std::endl;

	std::cout << "Different type of args:" << std::endl;
	Print(1, 2.5, 3, "4");

	Integer val{ 1 };

	Print(0, val, Integer{ 2 });
	
	return 0;
}

/*
1. Print(1, 2.5, 3, "4") ;
2. Print(2.5, 3, "4") ;
3. Print(3, "4") ;
4. Print("4") ;
5. Print() ;
*/
