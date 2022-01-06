#include <iostream>
#include <thread>

void Process() 
{
	std::cout << "Thread ID:" << std::this_thread::get_id() << std::endl;

	for (int i = 0; i < 5; ++i) 
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i << "..." << std::endl;
	}
}

int threads_funs() 
{
	std::thread t1(Process);
	
	//Returns the native type of the thread
	//On Windows, the native type is HANDLE
	//HANDLE handle = t1.native_handle();
	//On Linux, the native type is pthread_t
	pthread_t handle = t1.native_handle();

	// Windows API
	//SetThreadDescription(handle, "MyThread");	
	pthread_setname_np(handle, "MyThread");	
	
	auto id = t1.get_id();
	std::cout << "t1.get_id(): " << id << std::endl; 

	int cores = std::thread::hardware_concurrency();

	std::cout << "Number of cores:" << cores << std::endl;
	
	t1.join();

	return 0;
}