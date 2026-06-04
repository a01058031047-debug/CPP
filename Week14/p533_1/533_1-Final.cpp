#include <iostream>
using namespace std;

class TimeHMS 
{
    int hour;
    int min;
    int sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    // (1)
    TimeHMS operator+(const TimeHMS& t) 
    {
        int total =
            hour*3600 + min*60 + sec +
            t.hour*3600 + t.min*60 + t.sec;

        return TimeHMS(
            total/3600,
            (total%3600)/60,
            total%60
        );
    }

    // (2)
    TimeHMS operator-(const TimeHMS& t) 
    {
        int total1 = hour*3600 + min*60 + sec;
        int total2 = t.hour*3600 + t.min*60 + t.sec;

        int diff = total1 - total2;

        return TimeHMS(
            diff/3600,
            (diff%3600)/60,
            diff%60
        );
    }

    // (3)
    bool operator==(const TimeHMS& t) 
    {
        return hour==t.hour &&
               min==t.min &&
               sec==t.sec;
    }

    bool operator!=(const TimeHMS& t) 
    {
        return !(*this == t);
    }

    // (4)
    TimeHMS& operator++() 
    {
        hour++;
        return *this;
    }

    TimeHMS& operator--() 
    {
        hour--;
        return *this;
    }

    // (5)
    TimeHMS operator++(int) 
    {
        TimeHMS temp=*this;

        sec++;

        if(sec>=60){
            sec=0;
            min++;
        }

        if(min>=60){
            min=0;
            hour++;
        }

        return temp;
    }

    TimeHMS operator--(int) 
    {
        TimeHMS temp=*this;

        sec--;

        if(sec<0){
            sec=59;
            min--;
        }

        if(min<0){
            min=59;
            hour--;
        }

        return temp;
    }

    // (6)
    int& operator[](int index)
    {
        if(index==0) return hour;
        if(index==1) return min;
        return sec;
    }

    // (7)
    operator int() 
    {
        return hour*3600 + min*60 + sec;
    }

    // (8)
    operator double() 
    {
        return hour + min/60.0 + sec/3600.0;
    }

    // (9)
    friend TimeHMS operator*(int n,
                             const TimeHMS& t)
    {
        int total =
            n*(t.hour*3600 +
               t.min*60 +
               t.sec);

        return TimeHMS(
            total/3600,
            (total%3600)/60,
            total%60
        );
    }

    // (10)
    friend istream& operator>>(istream& in,
                               TimeHMS& t)
    {
        in >> t.hour >> t.min >> t.sec;
        return in;
    }

    friend ostream& operator<<(ostream& out,
                               const TimeHMS& t)
    {
        out << t.hour << "h "
            << t.min << "m "
            << t.sec << "s";
        return out;
    }
};

int main() 
{

    TimeHMS t1(1,20,30);
    TimeHMS t2(4,35,46);
    TimeHMS t3;

    t3 = t1 + t2;
    cout << "t1+t2 = " << t3 << endl;

    t3 = t1 - t2;
    cout << "t1-t2 = " << t3 << endl;

    cout << "t1==t2 : " << (t1==t2) << endl;
    cout << "t1!=t2 : " << (t1!=t2) << endl;

    ++t1;
    cout << "++t1 : " << t1 << endl;

    --t1;
    cout << "--t1 : " << t1 << endl;

    t1++;
    cout << "t1++ : " << t1 << endl;

    t1--;
    cout << "t1-- : " << t1 << endl;

    cout << "hour = " << t1[0] << endl;
    cout << "min  = " << t1[1] << endl;
    cout << "sec  = " << t1[2] << endl;

    cout << "(int)t1 = "
         << (int)t1 << endl;

    cout << "(double)t1 = "
         << (double)t1 << endl;

    t3 = 2 * t1;
    cout << "2*t1 = " << t3 << endl;

    cout << "\nInput hour min sec : ";
    cin >> t3;

    cout << "Input Time = "
         << t3 << endl;

    return 0;
}