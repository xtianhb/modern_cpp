
#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
void Print(const T& value) 
{
	if constexpr (std::is_pointer_v<T>) 
	{
		std::cout << *value << std::endl;
	}
	else if constexpr(std::is_array_v<T>) 
	{
		for (auto v : value) 
		{
			std::cout << v << ' ';
		}
		std::cout << std::endl;
	}
	else 
	{
		std::cout << value << std::endl;
	}
}



template<typename T>
std::string ToString(T value) 
{
	if constexpr (std::is_arithmetic_v<T>)
	{
		return std::to_string(value) ;
	}else 
	{
		return std::string{value} ;
	}
}

void CheckMode() {
	if constexpr (sizeof(void *) == 4) 
	{
		std::cout << "32-bit\n" ;
	}
	else if constexpr (sizeof(void *) == 8) 
	{
		std::cout << "64-bit\n" ;
	}
	else 
	{
		std::cout << "Unknown mode\n" ;
	}
}

int ifconstexpr() 
{
	std::cout << "**if const exprs**" << std::endl;

	int value{ 5 };
	Print(&value);
	int arr[] = { 1,2,3,4,5 };
	Print(arr);

	auto s = ToString(value) ;
	Print(s);
	
	CheckMode() ;

	return 0;
}