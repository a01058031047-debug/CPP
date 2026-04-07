//반환값으로 결과 전달
#include <iostream>

using namespace std;

struct MyTime {
    int hour;
    int min;
    int sec;
};

MyTime addTime(MyTime t1, MyTime t2) {
    MyTime result;

    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.sec %= 60;

    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;

    return result;
}