#include <iostream>
#include <limits>
#include <memory>
#include <except.hpp>
#include <vector>
#include <random>

#include <iostream>
#include <memory>
#include <vector>
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};
class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};
class Test {
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	Test() { 
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);

		/*pA = new A;
		pInt = new int;
		pStr = new char[1000];
		pArr = new int[50000];*/
	}
	~Test() {  
		std::cout << "~Test():Release resources" << std::endl; 
		throw std::runtime_error("Failed to initialize");
		/*delete pA;
		delete pInt;
		delete[]pStr;
		delete[] pArr;*/
	}
};


class test
{
public:
test() {std::cout << "Test();" << std::endl;};    
~test() {std::cout << "~Test();" << std::endl;};    
};

void ProcessRecords(int count) {
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	std::vector<int> p;
	p.reserve(count);
	std::vector<int> records;
	records.reserve(count);
	//Process the records
	for (int i = 0; i < count; ++i) {
		records.push_back(i);
	}

	std::default_random_engine eng;
	std::bernoulli_distribution dist;

	int errors{};

	for (int i = 0; i < count; ++i) 
    {
		try 
        {
			std::cout << "Processing record # : " << i << " ";
			if (!dist(eng)) {
				++errors;
				throw std::runtime_error("Could not process the record");
			}
			std::cout << std::endl;
		}
		catch (std::runtime_error &ex) 
        {
			std::cout << "[ERROR " << ex.what() << "]" << std::endl;
			if (errors > 4) {
				std::runtime_error err("Too many errors. Abandoning operation");
				ex = err;
				throw;
			}
		}
	}
}

int excepts (void)
{
	try 
    {
		//ProcessRecords(std::numeric_limits<int>::max());
		ProcessRecords(10);
	}
	catch (std::runtime_error &ex) 
    {
		std::cout << ex.what() << std::endl;
	}
	catch (std::out_of_range &ex) 
    {
		std::cout << ex.what() << std::endl;
	}
	catch (std::bad_alloc &ex)
    {
		std::cout << ex.what() << std::endl;

	}

	/*
	std::exception is the base class for all standard
	exception classes. It can be used as a handler if
	the exception handling code is same for all child
	class exception objects
	*/
	catch (std::exception &ex) 
    {
		std::cout << ex.what() << std::endl;
	}

	/*
	All-catch handler. Avoid as it does not give any
	information about the exception, so it is difficult
	to take any preventative action
	*/
	catch (...) 
    {
		std::cout << "Exception" << std::endl;
	}


    try 
    {
		Test t;
		throw std::runtime_error{ "Exception" };
	}
	catch (std::runtime_error &ex) 
    {
		std::cout << ex.what() << std::endl;
	}




	return 0;
}