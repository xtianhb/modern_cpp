
#include <iostream>
#include <optional>
#include <cstring>

const char * GetErrorString(int errorNo) {
	switch (errorNo) {
	case 0:
		return "Invalid input" ;
	case 1:
		return "Connection not established yet\n" ;
	default:
		return "" ;
	}
}
std::optional<const char *> GetErrorStringOp(int errorNo) {
	switch (errorNo) {
	case 0:
		return "Invalid input" ;
	case 1:
		return "Connection not established yet\n" ;
	default:
		return std::nullopt ;
	}
}
class ContactName {
	std::string first ;
	std::optional<std::string> middle ;
	std::string last ;

public:

	ContactName(const std::string& f, const std::optional<std::string>& m, const std::string& l)
		: first{f},
		  middle{m},
		  last{l} {
	}

	void Print() {
		std::cout << first << ' ' ;
		std::cout << middle.value_or("")<< ' ' ;
		std::cout << last << ' ' ;
		std::cout << '\n' ;
	}
};




int optional17() 
{
	std::cout << "** optional **" << std::endl;

	auto f = strlen("") ;
	std::cout << f << std::endl;
	
	ContactName n1{"Umar", "Majid", "Lone"} ;
	ContactName n2{"Ayaan", "", "Lone"} ;

	n1.Print() ;
	n2.Print() ;

	return 0 ;
	
	std::optional<int> value{5} ;
	if(value.has_value()) 
	{
		std::cout << value.value() << std::endl ;
	}
	if(value) 
	{
		std::cout << *value << std::endl; 
	}

	value = 1 ;
	value.reset() ;
	//auto message = GetErrorString(1) ;
	//if(strlen(message) != 0) {
	//	std::cout << message << std::endl; 
	//}else {
	//	std::cout << "Unknown error number\n" ;
	//}

	try{
	auto errorMessage = GetErrorStringOp(4) ;

	//Return contained value or the argument passed in value_or
	std::cout << errorMessage.value_or("Default") << std::endl ;
	
	if(errorMessage.has_value())
	{
		//Throws exception std::bad_optional_access if no value
		std::cout << errorMessage.value() << std::endl ;
	}else 
	{
		std::cout << "Unknown error number\n" ;
	}

	errorMessage = GetErrorStringOp(4) ;
	
	if(errorMessage) 
	{
		//Undefined behavior when no value exists in optional
		std::cout << *errorMessage << std::endl ;
	}else 
	{
		std::cout << "Unknown error number\n" ;
	}
	}catch(std::exception &ex) 
	{
		std::cout << "Exception:"<< ex.what() << std::endl ;
	}
	
	return 0;
}