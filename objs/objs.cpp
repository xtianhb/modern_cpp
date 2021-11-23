
#include <objs.hpp>
#include <iostream>

/* 
OOO REVIEW

Abstraction:  The main purpose of abstraction is hiding the unnecessary 
details from the users. Hides the internal implementation details.
The objects have interfaces that abstratc the inner working.

Encapsulation: Refers to the bundling of data, along with the methods that 
operate on that data, into a single unit, and restricting the access 
to some of an object's components.

Inheritance: is the mechanism of basing an object or class upon another 
object (prototype-based inheritance) or class (class-based inheritance), 
retaining similar implementation. Promotes reuse and extensebility.

Composition: Signifies relation between objects. It has some characteristic.

Polymorphism: Common behaviour with different implementations. Different
objects can have similar behaviour with a different impl. 
Overloading, virtual functions, templates.
Promotes reuse, scalability, extensibility.

*/


void TestObjs(void)
{
    std::cout << "TEST OBJS" << std::endl;

    const cCar * Car; 
    std::cout << "A" << std::endl;
    Car = new const cCar(); // Default constructor
    // Const qualifier, qualifies *this* pointer. Object, members, constant
    std::cout << "B" << std::endl;
    cCar().PrintCars();
    std::cout << "C" << std::endl;
    Car->PrintCars();
    std::cout << "D" << std::endl;
    Car->DashBoard();

    cCar * nCar;
    nCar = new cCar(123, 456.7); //Default constructor
    nCar->Acc();
    nCar->DashBoard();
    delete nCar;

    delete Car;

    std::cout << "------------" << std::endl;

    // Structs
    Point Start, End;
    Start.x=1; Start.y=2;    
    DrawLine(Start, End);

    std::cout << "------------" << std::endl;

    // Copy constructor
    int n = 1;
    int * p1 = &n;
    int *p2 = p1; //Shallow copy
    int *p3 = new int(*p1); //Deep copy

    Integer Val1(5);
    Integer Val2(Val1);
    std::cout << Val1.GetVal() << std::endl;

    // If there is one or more of 
    //      Destructor, Copy constructor, or Copy assignment
    // then the three should be defined.
    // Add deep copy

    std::cout << "------------" << std::endl;

    Int A;
    Int B(3);
    //Int C(A); Not possible. Deleted default copy ctor.
    //A.SetValue(3.0); Not possible. Deleted 

    return;
}

Integer::Integer(const Integer & Obj)
{
    p = new int( *Obj.p);
}
Integer::~Integer()
{
    delete p;
}
Integer::Integer()
{
    std::cout << "Integer()" << std::endl;
    p = new int(0);
}
Integer::Integer(int v)
{
    std::cout << "Integer(v)" << std::endl;
    p = new int(v);
}
int Integer::GetVal() const
{
    std::cout << "GetVal()" << std::endl;
    return *p;
}
void Integer::SetVal(int v)
{
    std::cout << "SetVal(v)" << std::endl;
    *p = v;
}

// Static variable
int cCar::TotalCars = 0;

void cCar::PrintCars(void)
{
    // No *this* pointer
    std::cout << "   Total=" << TotalCars << std::endl;
}

void cCar::DashBoard(void) const
{
    // Const qualifier, qualifies *this* pointer.
    // Object, memebers, constant
    std::cout << "Fuel=" << Fuel; 
    std::cout << " Passengers=" << Passengers;
    std::cout << " Speed=" << Speed;
    std::cout << std::endl;
}

void Foo(cCar &Car)
{
    return;
}

cCar::~cCar()
{
    std::cout << "~cCar"<< std::endl;
    TotalCars--;
}


cCar::cCar(void):cCar(0)
{
    // Third
    std::cout << "cCar()"<< std::endl;
}

cCar::cCar(int p ):cCar(p,0.0)
{
    // Second
    std::cout << "cCar(p)"<< std::endl;
}

cCar::cCar(int p, float f)
{
    // First
    std::cout << "cCar(p,f)"<< std::endl;
    Foo(*this);
    TotalCars++;

    Fuel = f;
    Passengers = p;
    Speed=0;
}

void cCar::Acc()
{
    //implicit -this- pointer.
    //this->Speed ++;
    Speed++;
    Fuel -=0.01;
    std::cout << "Acc()" << std::endl;
}

void cCar::Brake()
{
    Speed=0;
}

void cCar::FillFuel(float f)
{
    Fuel += f;
}

void DrawLine(Point Start, Point End)
{
    std::cout << "DrawLine: " ;
    std::cout << Start.x << ", " << Start.y << std::endl;
}