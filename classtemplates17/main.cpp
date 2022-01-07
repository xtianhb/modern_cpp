#include <iostream>

int ifconstexpr();
int fold_exprs();
int ctad();
int trait_suff();

int main(void)
{
    std::cout << "Class template argument deduction" << std::endl;

    ctad();
    fold_exprs();
    trait_suff();
    ifconstexpr();
    return 0;
}