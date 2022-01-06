//void FooDep() throw(int, float)
//{
	//ERROR
//}

static void Foo() noexcept
{

}

void Bar()
{

}

int no_except()
{
	//void (*p)() noexcept; // ERROR C++17
	void (*p)();
	p = Bar;
	p = Foo;
	p() ;
	
	return 0;
}