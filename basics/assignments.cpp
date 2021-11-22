//Implement the following functions using pointer arguments only

#include <iostream>
#include <assignments.hpp>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-parameter"

void RunAssignments(void)
{
    TestAdd();
    TestAdd();
    TestSwap();
    TestFactorial();

    TestAddRef();
    TestFactorialRef();
    TestSwapRef();

    ConstRef();

}


 
//Swap two numbers through reference arguments
void SwapRef(int &a, int &b) 
{
    int c;
    c=a;
    a=b;
    b=c;
}
void TestSwapRef() 
{
    int a=11, b=20;
    int &ra=a, &rb=b;
    cout << "TestSwapRef"  << endl;
    cout << ra << " " << rb << endl;
    SwapRef(a, b);
    cout << ra << " " << rb << endl;
}

 //Find factorial of a number and return that through a reference parameter
void FactorialRef(int a, int &result)
{
    result=1;
    while (a>0)
    {
        result *= a;
        a -= 1;
    }
}
void TestFactorialRef()
{
    int a, Result;
    cout << "TestFactorialRef" << endl;
    a=5; Factorial(&a, &Result);
    cout << "5! = " << Result << endl;
    a=4; Factorial(&a, &Result);
    cout << "4! = " << Result << endl;
    a=3; Factorial(&a, &Result);
    cout << "3! = " << Result << endl;
    a=2; Factorial(&a, &Result);
    cout << "2! = " << Result << endl;
}




//void Add(int a,int b, int &result) 
//Add two numbers and return the result through a reference parameter
void AddRef(int a, int b, int &result) 
{
    result = a + b;
}
void TestAddRef() 
{
    int a=5, b=10, Result;
    int &Ref = Result;
    AddRef(a, b, Ref);
    AddRef(a, b, Result);
    cout << "Add Ref = " << Result << endl;
}

//void Factorial(int *a, int *result);       
//Generate the factorial of a number and return that through the second pointer argument
void Factorial(int *a, int *result)
{
    *result=1;
    while (*a>0)
    {
        *result *= *a;
        *a -= 1;
    }
}
void TestFactorial()
{
    int a, Result;

    a=5; Factorial(&a, &Result);
    cout << "5! = " << Result << endl;
    a=4; Factorial(&a, &Result);
    cout << "4! = " << Result << endl;
    a=3; Factorial(&a, &Result);
    cout << "3! = " << Result << endl;
    a=2; Factorial(&a, &Result);
    cout << "2! = " << Result << endl;
}

//void Swap(int *a, int *b) ;  
//Swap the value of two integers
void Swap(int *a, int *b) 
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
void TestSwap() 
{
    int a=1, b=2;
    cout << "TestSwap " <<endl;
    cout << "  " << a << " " << b << endl;
    Swap(&a, &b);
    cout << "  " << a << " " << b << endl;
}

// int Add(int *a, int *b) ;    
//Add two numbers and return the sum
int Add(int *a, int *b)
{
    return  *a+*b;
}
void TestAdd()
{
    int a,b, *pa, *pb;
    pa=&a; 
    pb=&b;
    a=1; b=5;
    cout << "TestAdd = " << Add(pa, pb) << endl;
}

//void AddVal(int *a, int *b, int *result); 
//Add two numbers and return the sum through the third pointer argument
void AddVal(int *a, int *b, int *result)
{
    *result = *a+*b;
}
void TestAddVal()
{
    int a,b,c, *pa, *pb, *pc;
    pa=&a; 
    pb=&b;
    pc=&c;
    a=1; b=5;
    AddVal(pa, pb, pc); 
    cout << "TestAddAll = " << c << endl;
}


void ConstRef(void)
{

    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;
    cout << "ref_x2=" << ref_x2 << endl;
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ;
    int *const ptr2 = &x ;
    const int * const ptr3 = &x ;
    
    //Find which declarations are valid. If invalid, correct the declaration
    const int *pt43 = &MAX ;
    const int *ptr5 = &MAX ;
    
    const int &r1 = ref_x1 ;
    const int &r2 = ref_x2 ;
    
    const int * &p_ref1 = ptr1 ;
    int * const &p_ref2 = ptr2 ;
}

