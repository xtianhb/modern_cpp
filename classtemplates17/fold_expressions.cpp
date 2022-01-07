#include <iostream>

// For the recursion, a Sum with 0 args
// Overload template
auto Sum1() 
{
	return 0 ;
}
// The variadic template
template<typename T, typename ...Args>
auto Sum1(T a, Args...args) 
{
	// Binary operator
	return a + Sum1(args...) ;
}
/*
 * Sum(1,2,3,4,5) ;
 * return 1 + Sum(2,3,4,5) ;
 * return 2 + Sum(3,4,5) ;
 * return 3 + Sum(4,5) ;
 * return 4 + Sum(5) ;
 * return 5 + Sum() ;
 * return 5 + 0 ;
 * Folding reduce or acumulate
 *  1 + (2 + (3 + (4 + (5 + 0))))
 *  1 + (2 + (3 + (4 + 5)))
 *  1 + (2 + (3 + 9))
 *  1 + (2 + 12)
 *  1 + 14
 *  15
 */



// Fold expressions, more modern approach c++17

template<typename...Args>
auto Sum2(Args...args) 
{
	return (args + ...) ;   //Unary right fold
	//return (... + args) ;   //Unary left fold
}

template<typename...Args>
auto Sum3(Args...args) 
{
	//return (0 + ... + args) ;   //Binary left fold
	return (args + ... + 0) ;   //Binary right fold
}
/*
 * Unary Right Fold
 * Sum2(1,2,3,4,5)
 * (1 +(2 + (3 + (4 + 5))))
 *
 * Unary Left Fold
 * ((((1 + 2) + 3) + 4) + 5)
 */


/*
 * Binary Right fold
 * 1 + (2 + (3 + (4 + (5 + 0))))
 *
 * Binary Left Fold
 * (((((0+1)+2) + 3) + 4) + 5)
 */

/*
Operator that can be used with fold expressions
 + - * / % ^ & | = < > << >> += -
= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*

// Default for empty packs unary
&&          - true
||          - false
,           - void()
Others      - ill-formed: error
 */

template<typename...Args>
bool AnyOf(Args...args) 
{
	return (... || (args % 2 == 0)) ;
}
template<typename...Args>
bool AllOf(Args...args) 
{
	return (... && (args % 2 == 0)) ;
}

template<typename...Args, typename Predicate>
bool AnyOf2(Predicate p, Args...args) 
{
	return (... || p(args)) ;
}

int fold_exprs() 
{
	std::cout << "**folding expressions**" << std::endl;

	auto result1 = Sum1(1,2,3,4,5) ;
	std::cout << result1 << std::endl;

	auto result2 = Sum2(1,2,3,4,5) ;
	std::cout << result2 << std::endl;

	auto result3 = Sum3() ;
	std::cout << result3 << std::endl;

	std::cout << std::boolalpha ;
	std::cout << "Any even?" << AnyOf(10,3,5) << std::endl; 
	std::cout << "All even?" << AllOf(10,30,52) << std::endl;

    std::cout << "Any even?" << AnyOf2([](int x){return x % 2 == 0;},10,3,5) << std::endl; 

	return 0;
}
