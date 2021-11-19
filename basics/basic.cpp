#include <iostream>
#include <climits>
#include <cfloat>
#include <string>

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

    int number;

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