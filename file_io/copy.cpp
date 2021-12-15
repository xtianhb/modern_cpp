#include <iostream>
#include <string>
#include <file_io.hpp>

#include <filesystem>
//  Add g++ option: --std=c++17 
using namespace std::filesystem;
int str_test()
{
    std::string filename;

    filename = "/home/user";
    std::cout << filename << std::endl;

    filename = "c:\temp\newfile.txt";
    std::cout << filename << std::endl;

    filename = R"(c:\temp\newfile.txt)";
    std::cout << filename << std::endl;

    filename = R"MYDELIM__(Raw string literal "(In C++)" )MYDELIM__";
    std::cout << filename << std::endl;

    return 0;
}
int file_test1()
{
    // The program is in a build dir
    path p{ R"(../files)" };
    
    std::cout << "p.has_filename():" << std::endl;
    if ( p.has_filename() )
    {
        std::cout << p.filename() << std::endl;
    }

    std::cout << "path iterator:" << std::endl;
    for(const auto &x: p)
    {
        std::cout << x << std::endl;
    }

    // The program is in a build dir
    // It may failt here if path is not found
    std::cout << "directory iterator:" << std::endl;
    directory_iterator beg{p};
    directory_iterator end{}; // Empty object
    while (beg != end)
    {
        std::cout << *beg << std::endl;
        beg++;
    }

    return 0;
}


#include <fstream>

void Write()
{
    // The program is in a build dir
    std::ofstream out{"../files/data.txt"};
    out << "Hello world" << std::endl;
    out << 10 << std::endl;
    out.close();
}
int Read()
{
    // The program is in a build dir
    std::ifstream input{"../files/data.txt"};
    if(input.fail())
    {
        std::cout << "Could not open the file" << std::endl;
        return -1;
    }
    if(!input.is_open())
    {
        std::cout << "Could not open the file" << std::endl;
        return -1;
    }

    std::string message;
    std::getline(input, message);

    int value;
    input >> value;

    input >> value;
    if(input.fail())
    {
        std::cout << "input failed" << std::endl;
    }
    if(input.eof())
    {
        std::cout << "end of file" << std::endl;
    }

    input.clear();
    //input.setstate(std::ios::failbit)

    if(input.good())
    {
        std::cout << "I/O operations successful" << std::endl;
    }
    else
    {
        std::cout << "I/O operations failed" << std::endl;
    }

    std::cout << message << ":" << value << std::endl;

    input.close();

    return 0;
}
int file_test2()
{
    std::cout << "FSTREAM TESTS 2" << std::endl;
    Write();
    Read();
    return 0;
}



int file_test3()
{
    std::cout << "FSTREAM TESTS 3" << std::endl;
    
    path source( current_path() );
    source /= "../file_io.cpp";
    std::cout << source << std::endl;
    
    path dest( current_path() );
    dest /= "../copy.cpp";
    std::ifstream input {source};
    if (!input)
    {
        std::cout << "source not found" << std::endl;
        return -1;
    }

    std::ofstream output {dest};

    std::string line;
    while ( !std::getline(input, line).eof() )
    {
        output << line << std::endl;
    }

    output.close();
    input.close();

    return 0;
}



int file_io(void)
{
    str_test();
    file_test1();
    file_test2();
    file_test3();
    return 0; 
