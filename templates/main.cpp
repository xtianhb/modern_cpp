
#include <iostream>
#include <templates.hpp>
#include <integer.hpp>
#include <variadic.hpp>
#include <classtemp.hpp>
#include <aliases.hpp>

int main()
{
    std::cout << "//TEMPLATES>>" << std::endl;

    templates();
    TestInteger() ;
    variadic();
    classtemp(); 
    expl();
    partial_spec();
    aliases();
    std::cout << ">>TEMPLATES//" << std::endl;

    return 0;
}