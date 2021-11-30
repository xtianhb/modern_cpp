#include "mem2.hpp"
#include "integer.hpp"
#include <iostream>
#include <memory>

// Smart pointers
// Unique pointer: not shared with other parts of the code.


void Display (Integer * p)
{
	if(p==nullptr)
		return;
	else
		std::cout << p->GetValue() << std::endl;
}

// Factory function
Integer * GetPointer(void)
{
	Integer * p = new Integer{};
	return p;
}
void Store(std::unique_ptr<Integer> & p) // pass p as value!
{
	std::cout << "Storing data into a file:" << p->GetValue() << std::endl;
}
void Operate(int value)
{
	std::unique_ptr<Integer> p { GetPointer() } ;

	if (p==nullptr)
	{
		//p = new Integer {};
		p.reset( new Integer{value} );
	}
	p->SetValue(100);
	Display(p.get());
	Store(p);
	//delete p;	
	//p = nullptr; // overlodaded = deletes previous pointer. not needed.
	//p = new Integer;
	p.reset( new Integer{} );
	*p = __LINE__;
	Display(p.get());
	//delete p;
	
	return;
}







int main() 
{
	std::cout << "--MEM2--" << std::endl;

	//Operate(1234);

	//SharedPtrTest();

	//WeakPtrTest();

	//TestCircular();

	//UniqueDeleter();

	//SharedDeleter();

	Dynamic();




	std::cout << "--------" << std::endl;
	return 0;
}
