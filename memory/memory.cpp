#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

void TestMem(void)
{
    std::cout << "TEST MEM" << std::endl;

    int * p;
    
    p = (int *) malloc(sizeof(int));
    if (p!=nullptr)
    {
        *p=5;
        std::cout << *p << std::endl;
        free(p);
        p = nullptr;
    }

    p = (int *) calloc(1, sizeof(int));
    if (p!=nullptr)
    {
        std::cout << *p << std::endl;
        free(p);
        p = nullptr;
    }

    p = new int(10);
    std::cout << *p << std::endl;
    delete p;
    p = nullptr;

    p = new int[10]{1,2,3,4,5};
    for (int i=0; i<5; i++)
    {
        std::cout << p[i] << ", " ;
    }
    std::cout << std::endl;
    delete [] p;
    p = nullptr;

    char * s;
    s = new char[32];
    strcpy(s, "Hello world");
    std::cout << s << std::endl;
    delete [] s;
    s=nullptr;

    int a2d1[2][3]={ {1,2,3},
                    {4,5,6}};

    int a2d2[2][3]={ 1,2,3,
                    4,5,6};

    
    int *p1 = new int[3] ;
    int *p2 = new int[3] ;
    int ** pData = new int * [2];
    pData[0] = p1;
    pData[1] = p2;

    


}