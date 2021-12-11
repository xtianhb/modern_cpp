#include <cassert>
#include <iostream>
#include <goodies.hpp>
// Strings
#include <cstring>
#include <string>
#include <sstream>
#include <initializer_list>
#include <vector>


union test
{
    // memory shared for all members
    // size of union size of largest
    int x;
    char ch;
    test()
    {
        std::cout << "cctor"<< std::endl;
    }
    ~test()
    {
        std::cout << "dctor" << std::endl;
    }
};

void unions()
{
    test t;
    std::cout << t.ch << std::endl;
    t.x=1000;
    std::cout << t.ch << std::endl;
}



void vector(void)
{

    std::vector<int> data{1,2,3,4};

    for(int i=0; i<5; i++)
    {
        data.push_back(i*5);
    }
    
    // access
    for( int i=0; i<static_cast<int>(data.size()); i++)
    {
        std::cout << data[i] << std::endl;
    }
    for(auto x: data)
    {
        std::cout << x << std::endl;    
    }

    // delete
    data.erase(data.begin());  // remove at position

    // insert
    auto it = data.begin() +5;
    data.insert(it, 500);
}


class Bag
{
    int arr[10];
    int m_size{};
public:
    Bag(std::initializer_list<int> values)
    {
        assert(values.size() < 10);
        auto it = values.begin();
        while( it != values.end() )
        {
            Add(*it);
            it++;
        }
    }
    void Add(int value)
    {
        assert(m_size<10);
        arr[m_size++] = value;
    }
    void Remove()
    {
        --m_size;
    }
    int operator[](int index)
    {
        return arr[index];
    }
    int GetSize() const
    {
        return m_size;
    }
};

void Print(std::initializer_list<int> values)
{
    for(auto x: values)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// list initializer
void init_list()
{
    //std::initializer_list<int> data = {1,2,3,4};
    Bag B{1,2,3,4};

    for( auto x: {1,2,3,4})
        std::cout << x << " ";
    std::cout << std::endl;


    return;
}


// works as literal
constexpr int GetNumber()
{
    return 43;
}
constexpr int Max(int x, int y)
{
    if(x>y)
        return x;
    return y;
}
constexpr int Add(int x, int y)
{
    return x+y;
}
void const_expr()
{
    constexpr int i = 10; //compile time
    int arr1[i];

    const int j = GetNumber(); //compile time
    int arr2[j];

    constexpr int k = GetNumber();  // Compile time
    int arr3[k];

    int x = GetNumber(); // Normal, at run time

    constexpr int sum = Add(3,5);

    constexpr int max = Max(3,5);

    // Literal types, void, scalars, refs, etc.
    
    return ;
}




// User defined literals

class Distance
{
    long double m_Km;
public:
    Distance(long double km):m_Km{km}
    {

    }
    long double GetKm() const
    {
        return m_Km;
    }
    void SetKm(long double val)
    {
        m_Km = val;
    }


};

Distance operator"" _mi(long double val)
{
    // Replaces _mi operator functions
    // Creates new object with this value
    return Distance{val * 1.6};
}
Distance operator"" _meters(long double val)
{
    // Replaces _mi operator functions
    // Creates new object with this value
    return Distance{val /1000};
}
void literals()
{
    Distance dist1{ 32.0 };
    Distance dist2{ 88.0_mi };
    Distance dist3{ 1580.0_meters };


}



// Stream strings

void Stream_Strings()
{
    //int a=5, b=6;
    //int sum = a+b;
    //std::cout << "Sum of " << a << " & " << b  << " is: " << sum << std::endl;

    std::stringstream ss;
    //std::istringstream is;
    //std::ostringstream os;

    if (0)
    {
        ss.str(); // Read
        ss.str(""); // Assign 
        ss << 5;
        ss.str(""); // Assign 
        auto ssum1 = ss.str();
        auto ssum2 = std::to_string(5);
        std::cout << ssum1 << std::endl;
        std::cout << ssum2 << std::endl;
    }
    
    int a;
    std::string data = "10 20 50";
    ss.str(data);
    while ( ss >> a ) // return bools after extraction
    {
        std::cout << a << std::endl;
    }

    int x = std::stoi("53");

    return;
}


// Assingment
std::string ToUpper(const std::string &input)
{
    int n = input.length();
    std::string upper;
    if (n>0)
    {
        char c;
        for(int i=0; i<n; n++)
        {
            upper += toupper(input[i]);
        }
    }
    return upper;
}


// Modern strings
std::string mcombine(const std::string &first, const std::string &last)
{
    std::string fullname = first + last;
    return fullname;
}

void mstrings()
{
    std::cout << "//MSTRINGS>>" << std::endl;

    std::string first, last, fullname;
    std::getline(std::cin, first);
    std::getline(std::cin, last);

    fullname = mcombine(first, last);

    std::cout << fullname << std::endl;
    printf("%s", fullname.c_str());
    std::cout << "<<MSTRINGS//" << std::endl;

    std::string a = "a a";
    std::string b("b b");
    std::string c{"c c"};

    return;
}

void modern_strings(void)
{
    // Initialize
    std::string s = "Hello";
    s = "Hello"; //Assignment operator overloaded

    // Access
    // Assignment operator overloaded
    s[0] = 'W'; 
    char ch = s[0];
    // Move operator overloaded
    std::cout << s << std::endl;
    std::cin >> s;
    std::getline(std::cin, s);

    // Size
    s.length(); // Constant time.

    // Insert & Cat
    std::string s1{"Hello"}, s2{"world"};
    // Plus operator has elision
    s = s1+s2;
    s += s1;

    int ipos=5;
    s.insert(ipos, "insert");

    // Comparison
    //if (s1 == s2 || s1>s2) 
    
    // Removal
    s.erase(0,5); // first 5 characters
    s.clear();
    s.erase();

    // Search
    auto pos = s.find("World", 0); 
    if (pos != std::string::npos)
    {
        // Found
    }

}

const char * Combine(const char *pFirst, const char*pLast)
{
    char * FullName = new char[strlen(pFirst) + strlen(pLast) + 1]; 
    strcpy(FullName, pFirst);
    strcat(FullName, pLast);
    return FullName;
}

void strings(void)
{
    std::cout << "//STRINGS>>" << std::endl;

    char first[10];
    char last[10];

    std::cin.getline(first, 10);
    std::cin.getline(last, 10);

    const char *pFullName = Combine(first, last);

    std::cout << pFullName << std::endl;
    delete[] pFullName;

    std::cout << "<<STRINGS//" << std::endl;

    return;
}



// Enums

enum class Color : long {RED=5, GREEN, BLUE};

void FillColor(Color color)
{
    if(color==Color::RED)
    {
        std::cout << "RED" << std::endl;
    }
    else if (color==Color::GREEN)
    {
        std::cout << "GREEN" << std::endl;
    }
    else if (color==Color::BLUE)
    {
        std::cout << "BLUE" << std::endl;
    }
}

enum TLight : char {RED='c', GREEN, YELLOW};

void enums(void)
{
    std::cout << "ENUMS" << std::endl;

    Color c = Color::RED;
    FillColor(c);
    FillColor(Color::GREEN);
    FillColor(static_cast<Color>(2));
    int x = static_cast<int>(Color::RED);
    std::cout << "-------" << std::endl;
}
