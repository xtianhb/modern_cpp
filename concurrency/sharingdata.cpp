#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>

const int SIZE = 10000;

static std::list<int> g_Data;
static std::mutex g_Mutex;

void Download() 
{
	for (int i = 0; i < SIZE; ++i) 
	{
		//Use std::lock_guard to lock a mutex (RAII)
		std::lock_guard<std::mutex> mtx(g_Mutex);
		//g_Mutex.lock(); // Dangerous using lock/unlock
		g_Data.push_back(i);
		if (i == 500)
			return;
		//g_Mutex.unlock(); // Dangerous using lock/unlock
	}
}

void Download2() 
{
	for (int i = 0; i < SIZE; ++i) 
	{
		//g_Mutex.lock(); // Dangerous using lock/unlock
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
		//g_Mutex.unlock(); // Dangerous using lock/unlock
	}
}

int sharing_data() 
{
	std::thread thDownloader(Download);
	std::thread thDownloader2(Download2);
	thDownloader.join();
	thDownloader2.join();
	std::cout << g_Data.size() << std::endl; 

	return 0;
}