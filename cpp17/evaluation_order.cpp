#include <iostream>

class EvaluationOrder 
{
public:
	EvaluationOrder& First(int) {
		std::cout << __func__ << std::endl;
		return *this;
	}
	EvaluationOrder& Second(int) {
		std::cout << __func__ << std::endl;
		return *this;
	}
};

int FirstSubExpression(int) 
{
	std::cout << __func__ << std::endl;
	return 0 ;

}
int SecondSubExpression(int) 
{
	std::cout << __func__ << std::endl;
	return 0 ;

}

int evaluation_order() 
{
	std::cout << "EVAL ORDER" << std::endl;

	EvaluationOrder Eval ;

	Eval.First( FirstSubExpression(0)).Second(SecondSubExpression(0) ) ;

	return 0;
}

