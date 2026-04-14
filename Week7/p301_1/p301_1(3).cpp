// main.cpp (테스트 코드)

#include <iostream>
#include "MyTime.h"

using namespace std;

int main()
{
    MyTime t1, t2, t3;

    
    t1.read();
    t2.read();

    
    cout << "t1: ";
    t1.print();

    cout << "t2: ";
    t2.print();

    
    t3 = t1.add(t2);

    cout << "t3 (t1 + t2): ";
    t3.print();

    
    MyTime t4;
    t4.convert(3661);

    cout << "convert(3661): ";
    t4.print();

    return 0;
}