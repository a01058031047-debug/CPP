
//(1) ample 객체 개수를 관리하는 정적 변수 count 와 printCount()
static int count;

static void printCount() 
{
    cout << "객체 개수 : " << count << endl;
}

int Sample::count = 0;

//(2) 생성자 Sample(const char* name) 에서 this 와 new 를 이용한 초기화
Sample(const char* name) 
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    count++;
}

//(3) 소멸자 ~Sample() 작성
~Sample() 
{
    delete[] name;
    count--;
}

//(4) 복사 생성자 작성
Sample(const Sample& other) 
{
    if (other.name != nullptr) 
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    else {
        name = nullptr;
    }
    count++;
}

//최종코드

#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char* name;
    static int count;   // 객체 개수 관리

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        count++;
    }

    // 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        count++;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
        count--;
    }

    // 객체 개수 출력 함수
    static void printCount() {
        cout << "객체 개수 : " << count << endl;
    }

    void printName() {
        if (name != nullptr)
            cout << "name : " << name << endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

int main() {
    Sample a("sample");
    Sample::printCount();

    Sample b(a);   // 복사 생성자 호출
    Sample::printCount();

    a.printName();
    b.printName();

    return 0;
}