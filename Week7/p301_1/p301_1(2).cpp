// MyTime.cpp (구현 파일)

#include <iostream>
#include <iomanip>
#include "MyTime.h"

using namespace std;

MyTime::MyTime() 
{
    hours = minutes = seconds = 0;
}

void MyTime::convert(double duration)
{
    int total = static_cast<int>(duration);

    hours = total / 3600;
    total %= 3600;

    minutes = total / 60;
    seconds = total % 60;
}

void MyTime::print()
{
    cout << setfill('0')
         << setw(2) << hours << ":"
         << setw(2) << minutes << ":"
         << setw(2) << seconds << endl;
}

MyTime MyTime::add(MyTime t)
{
    MyTime result;

    result.seconds = seconds + t.seconds;
    result.minutes = minutes + t.minutes + result.seconds / 60;
    result.seconds %= 60;

    result.hours = hours + t.hours + result.minutes / 60;
    result.minutes %= 60;

    return result;
}

void MyTime::reset()
{
    hours = minutes = seconds = 0;
}

void MyTime::read() 
{
    cout << "시간 입력 (시 분 초): ";
    cin >> hours >> minutes >> seconds;
}