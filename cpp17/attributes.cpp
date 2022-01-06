#include <cstdlib>
#ifdef __has_include
#if __has_include(<filesystem>)
#define FS 1
#include <filesystem>
#endif
#endif

#include <iostream>

[[deprecated("Don't use")]]
void Foo() 
{

}

class [[deprecated("Not allowed")]] A
{
	
} ;

//namespace [[deprecated("Not allowed")]] Old
//{
//}

//#pragma message("Test message")

class [[nodiscard]] Test
{

};
[[nodiscard]]

int &Square(int x) 
{
	int *p = new int{x} ;
	return *p;
}

Test Create() 
{
	return Test{} ;
}


[[deprecated("Use the template version instead")]]
[[nodiscard]]
int * CreateIntArray(size_t size) 
{
	return new int[size] ;
}

template<typename T>
[[nodiscard]] T * CreateArray(size_t size) {
	return new T[size] ;
}

int attributes() 
{
	std::cout << "ATTRIBUTES" << std::endl; 

	//CreateIntArray(5) ;
	//CreateArray<int>(3) ;
	return 0;
}
