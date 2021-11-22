#include <iostream>
#include <climits>
#include <cfloat>
#include <string>
#include <basic.hpp>

using namespace std;

void TestBasic(void)
{

    cout << "TestBasic" << endl;

    cout << "Hello" << " C++" << endl;
    cout << "INT_MAX=" << INT_MAX << endl;
    cout << "FLT_MAX=" << FLT_MAX << endl;
    
    bool bool_var = true;
    char char_var;
    wchar_t wch_var;
    char32_t ch32var;
    float f = 1.23456789123456789;
    double d = 1.23456789123456789;
    cout << "bool=" << bool_var << endl;
    cout << "float=" << f << endl;
    cout << "double=" << f << endl;

    int arr[5];
    int arr_[5]  {1,2,3,4,5};

    cout << "Hello world \n" << 45 << " " << 8.2f << endl;

    //int number;

    //cin >> number;
    //cout << "number=" << number << endl;

    char buf[32];
    if (0)
        cin >> buf;
    if (0)
    {
        cin.getline(buf, 32, '\n');
        cout << buf << endl;
    }
}


int TestAdd(int a, int b)
{
    cout << "TestAdd" << endl;
    return a+b;
}

int TestFactorial(int n)
{
    cout << "TestFactorial" << endl;
    int result = 1;
    for (int i=1; i<=n; i++)
    {
        result *= i;
    }
    return result;
}

//list-initialization ->  Uniform initialization
/*This is supported from C++11 version. 
The uniform initialization is a feature that permits the usage of a consistent 
syntax to initialize variables and objects which are ranging from primitive type to aggregates. 
In other words, it introduces brace-initialization that applies braces ({}) to enclose initializer values.
*/
void TestUniform(void)
{

    cout << "TestUniform" << endl;

    // Uniform initialization
    // Uniform syntax
    // Force init of scalar and vector
    // Prevents bugs of incompatible types

    int var1; // Uninitialized
    int var2 = 2; // Copy initialization
    int var3 (5);//Direct initialization
    std::string s1;
    std::string s2 ("test");

    char ca1[32];
    char ca2[32] = {'\0'};
    char ca3[32] = {'1','1','1','1'}; //Aggregate initialization
    char ca4[32] = {"Test"};

    int i1{}; // Value initialization
    int i2{5}; // Direct initialization

    char ca5[32]{};

    char ca6[32]{"Hello"};

    char *p1 = new char[32] {}; //Dynamic memory
    char *p2 = new char[32] {'1'}; //Dynamic init with uniform

    // Use uniform initialization for user defined types.

    // a vector containing two elements: 10 and 20
    //std::vector<int> v{10, 20};
    // a vector containing 10 elements: all 20
    //std::vector<int> w(10, 20);

    /*The potentially different behavior for something like initializing a 
    vector<int> might seem like one of those things you just have to memorize 
    to ace your next C++ interview, but it has pretty serious implications for how to write generic code. */

    // Initialize a vector with 5 elements; an unambiguously proper use of
    // list-initialization. There is no other easy way of doing this
    //std::vector<int> v{1, 2, 3, 4, 5};

    //Use parentheses to initialize in all cases. Use braces only for the specific behavior that braces provide.
    ///Avoid writing class interfaces in which such an ambiguity might arise.


}

void TestPointers(void)
{

    int x (10);
    cout << &x << endl;
    int *ptr = &x;
    cout << ptr << endl;
    *ptr = 1;
    int *n = nullptr;
    cout << n << endl;
    //cout << *n << endl; //segfault crash
    
    return;
}

void TestReference(void)
{   // reference: An alias for variables. They don't use memory.
    // lvalue: Object in memory, addressable, persistant, variables, consts, etc
    // rvalue: Temporary object, just created, returnin function, etc.
    int x = 10;
    int &Ref = x; // Always referent
    cout << "x = " << x << endl;
    cout << "ref = " << Ref << endl;
    cout << "&x = " << &x << endl;
    cout << "&ref = " << &Ref << endl;
}

void PrintConst(const int & Ref)
{
    // Receive a literal or a l-value
    //Ref cant be modified
    cout << Ref << endl;
}
void TestConst(void)
{   
    const int CONST1 = 12;
    const int CONST2 = 24;
    
    const int * ptr;
    const int * const ptrc = &CONST1;

    ptr = &CONST1;
    cout << "CONST1="<<*ptr<<endl;
    ptr = &CONST2;
    cout << "CONST2="<<*ptr<<endl;
    
    cout << "ptrc="<<ptrc<<endl;
    cout << "*ptrc="<<*ptrc<<endl;

    int x=10;
    PrintConst(x);

}


void TestAuto(void)
{

    auto i = 1;
    auto j = 2;
    auto k = i+j;
    auto f = i+4.5;
    auto t = 'd' + 2;

    cout << "i k -> " << i << " " << k << endl;
    cout << "k " << k << endl;

    static auto txt = "pepe";
    cout << "txt " << txt << endl;
    
    const int x= 10;
    auto var1 = x; // not const;
    const auto var2 = x; // const;
    auto &var3 = x; // Ref;
    auto ptr = &x; // AVOID USING THIS. KEEPS pointer type.
}

void RangeFor(void)
{
    int arr[] = {1,2,3,4,5};
    for (int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    return ;

    //with range
    for (auto i: arr)
    {
        cout << i << " " ;
    }
    for (const auto i: arr)
    {
        cout << i << " " ;
    }
    for (auto i: {1,2,3,4})
    {
        cout << i << " " ;
    }

    // int*       Array of ints
    int * Beg = begin(arr);
    int * End = end(arr);
    while (Beg != End)
    {
        cout << *Beg << " ";
        Beg++;
    }
    //This is how the range for loop is internally
    //auto range = arr;
    auto Begin = begin(arr);
    for(; Begin != End; Begin++)
    {
        auto v = *Begin;
    }


}


int AddOverL(int a, int b)
{
    return a+b;

}
double AddOverL(double a, double b)
{
    return a+b;

}
void OverLoading(void)
{
    // Static polymorphism
    // Name mangling
    cout << AddOverL(1,2) << endl;
    cout << AddOverL(1.2, 2.2) << endl;
    // extern disables name mangling for only one
}


//With declaration
void DefArgs(int x, int y, int z)
{
    cout << x << y << z << endl;
}
//No declaration
void DefArgs2(int x =  0, int y=1, int z=2)
{
    cout << x << y << z << endl;
}

// Too much overhead for fast requirements
int Square(int x)
{
    return x*x;
}

inline int SquareInl(int x)
{
    return x*x;
}

void TestSquares(void)
{
    int Result;
    int Val = 1;

    cout << "TEST SQUARE" << endl;

    cout << Square(2) << endl;

    Result = SquareM(Val+1); // Val+1*Val+1
    cout << Result << endl;

    Result = SquareInl(2);
    cout << Result << endl;

}


void Function(int a, int b, int &c)
{
    c = a + b;
}


void TestFuncPtr(void)
{
    int Res = 0;
    cout << "TESTFUNPTR" << endl;
    Function(1,5,Res);
    cout << Res << endl;

    void (*pf) (int, int, int &) = Function;
    (*pf)(10,20,Res);
    cout << Res << endl;

}


namespace ns1 {
    int fun(int a, int b)
    {
        return a+b;
    }
}
int fun(int a, int b)
{
    return a*b;
}

void TestNs()
{
    cout << "TEST NAMESPACE" << endl;
    
    cout << fun(3,4) << endl;
    cout << ns1::fun(3,4) << endl;
    using ns1::fun;
    cout << fun(3,4) << endl;
}