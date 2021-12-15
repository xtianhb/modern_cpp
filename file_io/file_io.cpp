#include <iostream>
#include <string>
#include <cstring>
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
    std::cout << "FSTREAM TEST 2" << std::endl;
    Write();
    Read();
    return 0;
}

int file_test3()
{
    std::cout << "FSTREAM TEST 3" << std::endl;
    
    path source( current_path() );
    source /= "../file_io.cpp";
    std::cout << source << std::endl;
    
    path dest( current_path() );
    dest /= "../files/copy.cpp";
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

void Write4()
{
    std::ofstream out("../files/test.txt");
    if(!out)
    {
        std::cout << "Could not open file for writing" << std::endl;
        return;
    }
    std::cout << "cur pos out: " << out.tellp() << std::endl;
    std::string message {"This is a C++ program about filestreams...\n"};
    for(char ch : message)
    {
        out.put(ch);
    }
    out.seekp(10);
    out.put('@');
}
void Read4()
{
    std::ifstream in("../files/test.txt");
    if(!in)
    {
        std::cout << "Could not open file for reading" << std::endl;
        return;
    }
    in.seekg(2);
    std::cout << "cur pos in: " << in.tellg() << std::endl;
    in.seekg(2, std::ios::cur); //be|cur|end
    std::cout << "cur pos in: " << in.tellg() << std::endl;
    in.seekg(-10, std::ios::end); //be|cur|end
    std::cout << "cur pos in: " << in.tellg() << std::endl;
    in.seekg(0);
    char ch;
    while(in.get(ch))
    {
        std::cout << ch ;;
    }
}
void FStream()
{

    std::string spath = "../files/FStream.txt";

    std::fstream stream{ spath };
    if(!stream)
    {
        std::cout << "file does not exist"<<std::endl;
        std::ofstream out {spath};
        out.close();
        stream.open(spath);
    }

    stream << "Hello world!\n" << std::endl;

    std::string line;
    stream.seekg(0);
    std::getline(stream, line);
    std::cout << line << std::endl;

    return;
}

int file_test4()
{
    std::cout << "FSTREAM TEST 4" << std::endl;
    Write4();
    Read4();
    FStream();
    return 0;
}




struct Record
{
    int id;
    char name[10];
};

void WriteRecord(Record *p)
{
    std::ofstream boutstream{"../files/records.dat", std::ios::binary | std::ios::out};
    boutstream.write((const char *)p, sizeof(Record));
}
Record ReadRecord()
{
    std::ifstream binstream{"../files/records.dat", std::ios::binary | std::ios::in};
    Record r;
    binstream.read( (char *)&r, sizeof(Record) );
    return r;
}
int file_test5()
{
    std::cout << "FSTREAM TEST 5" << std::endl;

    int num = 1234;
    
    std::ofstream txtstream("../files/text.dat");
    txtstream << num;

    std::ofstream binstream("../files/data.dat", std::ios::binary | std::ios::out);
    binstream.write((const char *)&num, sizeof(num) );
    binstream.close();

    std::ifstream boutstream("../files/data.dat", std::ios::binary | std::ios::in);
    boutstream.read((char*)&num,sizeof(num));
    std::cout << num << std::endl; 

    Record r;
    r.id=5678;
    std::strcpy(r.name,"streams");
    WriteRecord(&r);
    r = ReadRecord();


    return 0;
}



int file_io(void)
{
    if(0)
    {
        str_test();
        file_test1();
        file_test2();
        file_test3();
        file_test4();    
    }
    file_test5();


    return 0; 
}