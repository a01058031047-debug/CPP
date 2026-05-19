// (1) Rectangle 클래스를 상속하여 정의

class Rectangle : public Point 
{
private:
    int width, height;
};

// (2) 생성자에서 초기화 리스트 사용

Rectangle(int xx, int yy, int w, int h)
    : Point(xx, yy), width(w), height(h) {
}

// (3) draw 함수 재정의

void draw() 
{
    std::cout << x << "," << y
              << "에 가로 " << width
              << " 세로 " << height
              << "인 사각형을 그려라.\n";
}

// (4) protected를 private로 바꾸면

protected:
    int x, y;


    로 변경하면

//Rectangle에서 x, y 직접 접근 불가
//아래 코드가 오류 발생

std::cout << x << y;   // 오류

//왜냐하면 private 멤버는 부모 클래스 내부에서만 접근 가능하기 때문이다.
//따라서
//getter 함수 사용
//또는 protected 유지
//해야 함

// 최종 C++ 코드

#include <iostream>
using namespace std;

class Point 
{
protected:
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) {
    }

    void draw() 
    {
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

class Rectangle : public Point 
{
private:
    int width, height;

public:
    // 생성자
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) {
    }

    // draw 함수 재정의
    void draw() 
    {
        cout << x << "," << y
             << "에 가로 " << width
             << " 세로 " << height
             << "인 사각형을 그려라.\n";
    }
};

int main() 
{
    Rectangle r(2, 3, 100, 200);

    r.draw();

    return 0;
}