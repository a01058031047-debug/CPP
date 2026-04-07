// 포인터(pointer)로 결과 전달

#include <iostream>

using namespace std;

struct MyTime {
    int hour;
    int min;
    int sec;
};

void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    pt->sec = t1.sec + t2.sec;
    pt->min = t1.min + t2.min + pt->sec / 60;
    pt->sec %= 60;

    pt->hour = t1.hour + t2.hour + pt->min / 60;
    pt->min %= 60;
}