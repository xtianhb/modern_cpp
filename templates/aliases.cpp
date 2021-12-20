#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo)
{
	return "Empty";
}


//typedef const char *(*PFN)(int);

using PFN = const char *(*)(int); //ALIAS


void ShowError(PFN pfn)
{
	
}

// TYPEDEF: Not template compatible
//typedef std::vector < std::list<std::string>> Names;

// ALIAS:
//using Names = std::vector<std::list<std::string>>;

// ALIAS + TEMPLATE
template<typename T>
using Names = std::vector<std::list<T>>;
using StrNames = std::vector<std::list<std::string>>;

int aliases() 
{

	std::cout << "Aliases>>" << std::endl;

	Names<std::string> names_;
	StrNames name_str;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
