#include <iostream>


int attributes(void);
int feature_macros(void);
int ifswitch();
int inline17();
int nested_namespaces();
int no_except();
int Using_Lambda();
int structured_bindings();
int evaluation_order();
int mandatory_copy_elision();

int main(int, char**) 
{
    std::cout << "C++ FEATURES" << std::endl;

    nested_namespaces();
    feature_macros();
    attributes();
    ifswitch();
    inline17();
    no_except();
    Using_Lambda();
    structured_bindings();
    evaluation_order();
    mandatory_copy_elision();

    std::cout << "C++ FEATURES OK" << std::endl;
    
    return 0;
}
