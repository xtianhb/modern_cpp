#include <iostream>
#include <string>
#include <templates.hpp>

int temp1()
{
    std::cout << "Templates1>>" << std::endl;

    return 0;
}

int temp2()
{
    std::cout << "Templates2>>" << std::endl;

    return 0;
}

int temp3()
{
    std::cout << "Templates3>>" << std::endl;

    return 0;
}

int templates(void)
{
    temp1();
    temp2();
    temp3();


    return 0; 
}