#pragma once

void TestObjs(void);


class Int 
{
private:
    int Value=0;
public:
    // Directive, define default constructor.
    // Same applies to constc, copy const, assign const.
    Int() = default;     
    Int (int V)
    {
        Value=V;
    }
    // Don't synthesize copy const.
    Int(const Int &) = delete;
    void SetValue(int V)
    {
        Value = V;
    }
    // delete can be used in other functions
    void SetValue(float) = delete;
};




class Integer
{
private:
    int *p;
public:
    Integer();
    Integer(int v);
    Integer(const Integer &); //This is a copy constructor
    int GetVal()const;
    void SetVal(int v);
    ~Integer();
};


class cCar
{
//private: by default
private:
    //Non static data member initializer
    float Fuel=5.0;
    float Speed=0.0;
    int Passengers=0;

public:
    static int TotalCars; // Static member
    static void PrintCars(void); //Static funcion.
    void FillFuel(float amount);
    void Acc();
    void Brake();
    void DashBoard() const;

    cCar(int p, float f);
    cCar(int p );
    cCar(void);
    ~cCar();
};

void DrawLine(int , int , int , int );
struct Point
{
//Default access: public    
    int x;
    int y;
};
void DrawLine(Point Start, Point End);

class SInit
{
    //Non static data member initializer
    float a=1.0;
    int b=1;
    //Any other type.
    //Goes to default constructor.
};