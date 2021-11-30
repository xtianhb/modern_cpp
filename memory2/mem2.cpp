#include <string>
#include <iostream>
#include <memory>
#include "mem2.hpp"
#include <cstdlib>

class Project 
{
    std::string m_Name;
public:
    void SetName (const std::string &name)
    {
        m_Name = name;
    }
    void ShowProjectDetails() const
    {
        std::cout << "[Project Name ]" << m_Name << "\n";
    }
};

class Employee
{
    std::shared_ptr<Project> m_pProject{};
public:
    void SetProject( const std::shared_ptr<Project> &Prj )
    {
        m_pProject = Prj;
    }
    const std::shared_ptr<Project> & GetProject() const
    {
        return m_pProject;
    }

};
void ShowInfo( const std::shared_ptr<Employee> & emp)
{
    std::cout << "Employee project details: \n";
    emp->GetProject()->ShowProjectDetails();
} 
void SharedPtrTest()
{
    std::shared_ptr<Project> prj { new Project{} };
    prj->SetName("Video Decoder");

    std::shared_ptr<Employee> e1 { new Employee{} };
    e1->SetProject(prj);
    std::shared_ptr<Employee> e2 { new Employee{} };
    e2->SetProject(prj);
    std::shared_ptr<Employee> e3 { new Employee{} };
    e3->SetProject(prj);

    std::cout <<  "Ref count = " << prj.use_count() << "\n";

    ShowInfo(e1);
    ShowInfo(e1);
    ShowInfo(e3);

    prj->ShowProjectDetails();

}




class Printer
{
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p)
    {
        m_pValue = p;
    }
    void Print()
    {
        if(m_pValue.expired())
        {
            std::cout << "Resource is no longer valid" << std::endl;    
            return;
        }
        auto sp = m_pValue.lock(); //return shared pointer
        std::cout << "Value is: " << *sp << std::endl;
        std::cout << "RefCount=" << sp.use_count() << std::endl;
    }
};

void WeakPtrTest()
{
    Printer prn;
    int num{};
    num = 15;
    std::shared_ptr<int> p { new int{num} };
    prn.SetValue(p);
    // ...
    // Complex code...
    // ...
    // Compare value
    if (*p > 10)
    {
        p = nullptr; // Decrements ref count
    }
    prn.Print();
}

// Circular references
class employee;
class project 
{
public:
    std::shared_ptr<employee>  emp;
    project()
    {
        std::cout << "project()" << std::endl;
    }
    ~project()
    {
        std::cout << "~project()" << std::endl;
    }
};
class employee
{
public:
    std::weak_ptr<project> prj;
    employee()
    {
        std::cout << "employee()" << std::endl;
    }
    ~employee()
    {
        std::cout << "~employee()" << std::endl;
    }
};
void TestCircular()
{
    std::shared_ptr<employee> emp { new employee{} };
    std::shared_ptr<project> prj { new project{} };

    emp->prj = prj;
    prj->emp = emp;

}


struct Free
{
    void operator()(int *p)
    {
        free(p);
        std::cout << "pointer freed\n";
    }
};
void MyFree(int * p)
{
    free(p);
    std::cout << "pointer freed\n";
}
// We need to specify our free resource function
void UniqueDeleter()
{
    int *p1 = (int*)malloc(sizeof(int));
    *p1=100;
    std::cout << *p1 << "\n";
    free(p1);

    std::unique_ptr<int, Free> p2 { (int*)malloc(sizeof(int)), Free{} };
    *p2=100;
    std::cout << *p2 << "\n";

    std::unique_ptr<int, void(*)(int *)> p3 { (int*)malloc(sizeof(int)), MyFree };
    *p3=100;
    std::cout << *p3 << "\n";
    //free(p);

}


void SharedDeleter()
{
    std::shared_ptr<int> p1 { (int*)malloc(sizeof(int)), Free{} }; //obj fun
    //std::shared_ptr<int> p1 { (int*)malloc(sizeof(int)), MyFree }; //function
    *p1=100;
    std::cout << *p1 << "\n";


}


void Dynamic()
{
    // Template specialization
    std::unique_ptr<int[]> p1{new int[5]{1,2,3}};
    std::shared_ptr<int[]> p2{new int[5]{1,2,3}};
    p1[0] = 10;

    // Not recommended to allocate memory manually
    //std::unique_ptr <int> p3{new int{5}};
    auto p4 = std::make_unique<int>(5);  // <<Factory function variadic

    auto pa = std::make_unique<int[]>(5);
    pa[0]=10;

    //std::make_shared was added in C++20 for dynamic arrays

    

}