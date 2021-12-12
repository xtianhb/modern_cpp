#include <iostream>
#include <ooo.hpp>

class Animal
{
private:
// Accessible only to objects
    void Private()
    {

    }

public:
// Accesible public
    void Eat()
    {
        std::cout <<"Basic Eat"<<std::endl;
    }
    void Run()
    {
        std::cout <<"Basic Run"<<std::endl;
    }
    void Speak()
    {
        std::cout <<"Basic Speak"<<std::endl;
    }
protected:
// Accessible only to child classes and obj members
    void Protected()
    {

    }
};

// Public inheritance <- Recommended in C++
// Private inheritance: Converts all to private
// Protected inheritance: Keeps all private else protected
class Dog: public Animal
{
public:
    void Eat()
    {
        std::cout <<"Dog Eat"<<std::endl;
    }
        void Speak()
    {
        std::cout <<"Dog Speak"<<std::endl;
    }
};

void ooo()
{
    Dog D;
    D.Eat();
    D.Run();
    D.Speak();
    //D.Protected();//Not accessible
    //D.Private(); //Not accessible
}

// Constructors execute from base to child
// Destructors execute from child to base
// Base data members will be part of child