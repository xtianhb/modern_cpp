#include <iostream>
#include <string>
#include <basic.hpp>

int main()
{
    
    using namespace std;

    TestBasic();
    cout << TestAdd(10,20) << endl;
    cout << TestFactorial(5) << endl;
    TestUniform();
    TestPointers();

    return 0;
}


