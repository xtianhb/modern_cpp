#include <iostream>
#include <thread>
#include <future>

/* 
The threads share a state through the promise and future.
This is the way to extract return value from async task.
Share data between threads safely!
*/

int Operation(int count) 
{
	using namespace std::chrono_literals;
	int sum{};
	for (int i = 0; i < count; ++i) 
	{
		sum += i;
		std::cout << '.' << std::endl;
		std::this_thread::sleep_for(300ms);
		//std::chrono::seconds(1) 
	}

	return sum;
}

void async() 
{
	
	using namespace std::chrono_literals ;

	// std::launch::async, or std::launch::deferred: depends of compiler if not specified.
	// args are passed by value, otherwise must use std ref and cref.
	std::future<int> result;
	if(0)
		result = std::async(std::launch::async, Operation, 10);
	else
		result = std::async(std::launch::deferred, Operation, 10);
	
	std::this_thread::sleep_for(1s) ;
	
	std::cout << "main() thread continues execution...\n";

	if (result.valid()) 
	{
		
		auto timepoint = std::chrono::system_clock::now() ; // Used with wait_until
		timepoint += 1s ; 
		
		auto status = result.wait_until(timepoint); // Timepoint
		//auto status = result.wait_for(4s) ; // Not blocking. Duration

		switch(status) 
		{
		case std::future_status::deferred:  // Cannot wait this taks
			std::cout << "Deferred: Task is synchronous\n" ;
			break ;
		case std::future_status::ready:  // You can call get
			std::cout << "Ready: Result is ready\n" ;
			break ;
		case std::future_status::timeout: // Timeout after wait_for
			std::cout << "Timeout: Task is still running\n" ;
			break ;
		}

		//result.wait() ;
		//Operation(10) ;

		auto sum = result.get();
		std::cout << sum << std::endl;
	}
}