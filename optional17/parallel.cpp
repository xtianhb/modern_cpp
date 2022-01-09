#include <chrono>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>
#include <algorithm>
#include <execution>
// In linux, install libtbb-dev
// links with tbb

class Timer 
{
	std::chrono::steady_clock::time_point m_start ;
public:
	Timer():m_start{ std::chrono::steady_clock::now()} 
	{
		
	}
	void ShowResult( std::string_view message = "") 
	{
		auto end = std::chrono::steady_clock::now() ;
		auto difference = end - m_start ;
		std::cout << message
			<< ": "
			<< std::chrono::duration_cast<std::chrono::microseconds>(difference).count()
			<< " us" 
			<< std::endl;
	}
	void Reset()
	{
		m_start = std::chrono::steady_clock::now();
	}
};

constexpr unsigned VEC_SIZE{100} ;

std::vector<long> CreateVector() 
{
	std::vector<long> vec ;
	vec.reserve(VEC_SIZE) ;
	std::default_random_engine engine{ std::random_device{}() } ;
	std::uniform_int_distribution<long> dist{0, VEC_SIZE} ;
	for(unsigned i = 0 ; i < VEC_SIZE ; ++i) 
	{
		vec.push_back(dist(engine)) ;
	}
	return vec ;
}



int parallel17() 
{
	std::cout << "** parallel **" << std::endl;


	auto dataset = CreateVector() ;
	Timer t ;

	t.Reset();
	std::sort(dataset.begin(), dataset.end()) ;
	t.ShowResult("Accumulate time") ;

	t.Reset();
	std::sort(std::execution::par, dataset.begin(), dataset.end()) ;
	t.ShowResult("Accumulate time") ;
	
	t.Reset();
	auto result1 = std::accumulate(dataset.begin(), dataset.end(), 	0L) ;
	t.ShowResult("Accumulate time") ;

	t.Reset();
	auto result2 = std::reduce(dataset.begin(), dataset.end(), 0L) ;
	t.ShowResult("Accumulate time") ;

	return 0;
}

