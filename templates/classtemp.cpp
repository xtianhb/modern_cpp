#include <iostream>
#include <vector>



template<typename T, int size>
class Stack 
{
	T m_Buffer[size];
	int m_Top{ -1 };

public:

	Stack() = default;
	
	// Copy constructor
	//Stack(const Stack<T, size> &obj) // long
	Stack(const Stack &obj)  // short
	{
		m_Top = obj.m_Top;
		for (int i = 0; i <= m_Top; ++i) 
		{
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}

	void Push(const T &elem) 
	{
		m_Buffer[++m_Top] = elem;
	}

	void Pop();

	const T& Top()const 
	{
		return m_Buffer[m_Top];
	}

	bool IsEmpty() 
	{
		return m_Top == -1; 
	}

	/*
	Shorthand notation for class name as return type,
	because it appears inside the class
	*/
	static Stack Create();

};

template<typename T, int size>
void Stack<T, size>::Pop() 
{
	--m_Top;
}

template<typename T, int size>
/*
Longhand notation for class name as return type,
because it appears outside the class
//Stack<T, size> is class name
*/
Stack<T, size> Stack<T, size>::Create() 
{
	return Stack<T, size>();
}

int classtemp() 
{

	std::cout << "CLASSTEMP >>>" << std::endl;

	/*
	The template parameter list is part of the type of class.
	The following code will not work.

	Stack<float, 9> s = Stack<float, 10>::Create();
				 ^
	*/
	Stack<float, 10> s = Stack<float, 10>::Create();
	s.Push(3);
	s.Push(1);
	s.Push(6);
	s.Push(9);
	auto s2(s);
	while (!s2.IsEmpty()) {
		std::cout << s2.Top() << " ";
		s2.Pop();
	}
	Stack<char *, 5> ss;
	ss.Push((char*)"Hello");
	auto ss2(ss);
	return 0;
}



//////////////////////////////////////////////
//////////////////////////////////////////////



template<typename T>
class PrettyPrinter {
	T *m_pData;
public:
	PrettyPrinter(T *data) :m_pData(data) 
	{

	}
	void Print() 
	{
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() 
	{
		return m_pData;
	}
};


//Explicit specialization of a member function should appear outside the class
template<>
void PrettyPrinter<std::vector<int>>::Print() 
{
	std::cout << "{";
	for (const auto &x : *m_pData) 
	{
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}


template<>
class PrettyPrinter<char*> 
{
	char *m_pData;

public:
	PrettyPrinter(char *data) :m_pData(data) 
	{

	}

	void Print() 
	{
		std::cout << "{" << m_pData << "}" << std::endl;
	}

	char * GetData() 
	{
		return m_pData;
	}

};


//template<>
//class PrettyPrinter<std::vector<int>> 
//{
//	std::vector<int> *m_pData;
//public:
//	PrettyPrinter(std::vector<int> *data) :m_pData(data) 
//	{
//	}

//	void Print() 
//	{
//		std::cout << "{";
//		for (const auto &x : *m_pData) 
//		{
//			std::cout << x;
//		}
//		std::cout << "}" << std::endl;
//	}
//	std::vector<int> * GetData() 
//	{
//		return m_pData;
//	}
//};

int expl() 
{

	std::cout << "Explicit specialization class templates" << std::endl;

	//int data = 5;
	//float f = 8.2f;
	//PrettyPrinter<int> p1(&data);
	//p1.Print();
	//PrettyPrinter<float> p2(&f);
	//p2.Print();

	char *p{ (char*) "Hello world" };
	PrettyPrinter<char*> p3(p);
	p3.Print();
	//char * pData= p3.GetData(); // ERROR

	char *pData = p3.GetData();
	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();
	return 0;
}



//////////////////////////////////////////////
//////////////////////////////////////////////



//Primary or base template
template<typename T, int columns>
class PrettyPrinter2 
{
	T *m_pData;

public:
	PrettyPrinter2(T *data) :m_pData(data) 
	{
	}

	void Print() 
	{
		std::cout << "Columns:" << columns << std::endl;
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() 
	{
		return m_pData;
	}
};

//Partial specialization for value 80
template<typename T>
class PrettyPrinter2<T, 80> {
	T *m_pData;
public:
	PrettyPrinter2(T *data) :m_pData(data) {

	}
	void Print() 
	{
		std::cout << "Using 80 Columns"<< std::endl;
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};


template<typename T>
class SmartPointer 
{
	T *m_ptr;
public:
	SmartPointer(T *ptr) :m_ptr(ptr) 
	{
	}
	T * operator ->()
	{
		return m_ptr;
	}
	T & operator *() 
	{
		return *m_ptr;
	}
	~SmartPointer() 
	{
		delete m_ptr;
	}
};


//Partial specialization for array types
template<typename T>
class SmartPointer<T[]> 
{
	T *m_ptr;
public:
	SmartPointer(T *ptr) :m_ptr(ptr) 
	{
	}
	T & operator[](int index)  //subscript operator
	{
		return m_ptr[index];
	}
	~SmartPointer() 
	{
		delete[] m_ptr; // THIS!
	}
};


int partial_spec() 
{
	std::cout << "Partial specialization class templates" << std::endl;

	int data = 800;
	PrettyPrinter2<int, 80> p{ &data };
	p.Print();

	SmartPointer<int[]> s1{ new int[5] };
	s1[0] = 5;
	std::cout << s1[0] << std::endl;

	return 0;
}