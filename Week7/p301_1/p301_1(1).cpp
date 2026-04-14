// MyTime.h (헤더 파일)

#ifndef MYTIME_H
#define MYTIME_H

class MyTime
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    
    MyTime();

    
    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};

#endif