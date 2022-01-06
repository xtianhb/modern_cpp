
#pragma region constexpr lambda
#include <sstream>
#include <iostream>
//////////// constexpr lambda
template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}

class Product 
{
	std::string name;
	float price;

public:
	Product(const std::string &n, float p) :name(n), price(p) 
	{

	}

	void AssignFinalPrice() 
	{
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		//Capture this
		ForEach(taxes, [basePrice, this](float tax) 
		{
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
		});
	}

	float GetPrice()const 
	{
		return price;
	}

	auto GetDescription() 
	{
		return [*this](const std::string& header) 
		//return [this](const std::string& header) // Doesn't create copy.
		{
			std::ostringstream ost;
			ost << header << std::endl;
			ost << "Name : " << name << std::endl;
			ost << "Price : " << price << std::endl;
			return ost.str();
		};
		
	}
};

int Using_Lambda() 
{
	std::cout << "CONST EXPR LAMBDA" << std::endl; 

	Product *p = new Product { "Watch", 500 };
	//p->AssignFinalPrice();
	//std::cout << p->GetPrice() << std::endl;
	auto desc = p->GetDescription() ;
	delete p ;
	std::cout << desc("##############");

	// Automatically becomes constexpr for compile time
	auto f = [](int x,int y) 
	{
		return x + y ;
	};
	auto sum = f(3,5) ;
	printf("%d\n", sum) ;

	return 0;
}

#pragma endregion