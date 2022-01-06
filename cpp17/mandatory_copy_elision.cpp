#include <iostream>

#define DELETE_COPY_MOVE

class Number 
{
public:
	Number(int value) 
	{
		std::cout << "Parameterized ctor\n" ;
	}
#ifdef DELETE_COPY_MOVE
	Number(const Number &) = delete ;
	Number(Number &&) = delete ;
#else
	// Needed for elision in some conditions
	// C++17 not requires always copy/move
	Number(const Number &) 
	{
		std::cout << "Copy ctor\n" ;
	}
	Number(Number &&)
	{
		std::cout << "Move ctor\n" ;
	}
#endif
};

void Foo(Number n) 
{
	
} 

Number Create_Elision() 
{
	// Fails in some cases if copy/move are deleted

	// C++17 will not work with named return value
	// Mandatory elision needs a temporary.
	//Number n{0} ;
	//return n;  // Named return value optimization. LValue!
	

	// Elision works here with C++17 
	return Number{0}; // Return value optimization
}


template<typename T, typename...Args>
T Create_Elision(Args&&...args) 
{
	return T{args...} ;
}


int mandatory_copy_elision() 
{
	std::cout << "MANDATORY COPY ELISION" << std::endl;

	Number n1 = Number{3}; // Copy elision, temporary ommited. Not part of standard
	Foo(Number{3}) ; // Also creates a temporary
	auto n2 = Create_Elision();
	// Temporaries are elided

	auto n3 = Create_Elision<Number>(0) ;

	return 0;
}

/*
In C++17 some large objetcs can be returned by value thanks to elision.
Useful for factory functions templates, that don't support copy or move.
C++17 copy elision is mandatory for exprs LValue with RValue.
Cases:
Function returns temp by value
Object is init vy RValue
FUnction that accepts LValue invoked with RValue-

*/