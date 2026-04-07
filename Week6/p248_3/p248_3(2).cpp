// 참조(reference)로 결과 전달
 
#include <iostream>

using namespace std;

struct MyTime {
    int hour;
    int min;
    int sec;
};

void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    t3.sec = t1.sec + t2.sec;
    t3.min = t1.min + t2.min + t3.sec / 60;
    t3.sec %= 60;

    t3.hour = t1.hour + t2.hour + t3.min / 60;
    t3.min %= 60;
}