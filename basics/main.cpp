#include <iostream>
#include <string>
#include <basic.hpp>
#include <assignments.hpp>

#pragma GCC diagnostic ignored "-Wunused-parameter"

int main()
{
    
    using namespace std;

    TestBasic();
    cout << TestAdd(10,20) << endl;
    cout << TestFactorial(5) << endl;
    TestUniform();
    TestPointers();
    TestReference();
    TestConst();
    TestAuto();
    RangeFor();
    RunAssignments();
    OverLoading();
    DefArgs();
    TestSquares();
    TestFuncPtr();
    TestNs();
    return 0;
}


