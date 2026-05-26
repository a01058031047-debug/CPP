#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

// Canvas 클래스

class Canvas 
{
    int xMax, yMax;
    char** map;

public:
    Canvas(int x = 40, int y = 20) 
    {
        xMax = x;
        yMax = y;

        map = new char* [yMax];

        for (int i = 0; i < yMax; i++)
            map[i] = new char[xMax];
    }

    ~Canvas() 
    {
        for (int i = 0; i < yMax; i++)
            delete[] map[i];

        delete[] map;
    }

    void clear(char val = '.') 
    {
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                map[y][x] = val;
    }

    void draw(int x, int y, char val) 
    {
        map[y][x] = val;
    }

    void print(const char* title = "<Monster World>") {
        system("cls");

        cout << title << endl;

        for (int y = 0; y < yMax; y++) {
            for (int x = 0; x < xMax; x++)
                cout << map[y][x];

            cout << endl;
        }
    }

    char get(int x, int y) {
        return map[y][x];
    }

    int getMaxX() { return xMax; }
    int getMaxY() { return yMax; }
};


// Monster 클래스

class Monster {
protected:
    string name;
    string icon;
    int x, y;
    int nItem;

public:
    Monster(string n = "몬스터",
        string i = "M",
        int px = 0,
        int py = 0)
        : name(n), icon(i),
        x(px), y(py), nItem(0) {
    }

    virtual ~Monster() {
        cout << "[" << name << " 소멸]" << endl;
    }

    virtual void move(int** map, int maxx, int maxy) {
        switch (rand() % 8) {
        case 0: x--; break;
        case 1: x++; break;
        case 2: y--; break;
        case 3: y++; break;
        }
        clip(maxx, maxy);
    }

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        if (x >= maxx) x = maxx - 1;
        if (y >= maxy) y = maxy - 1;
    }

    virtual void draw(Canvas* canvas) {
        canvas->draw(x, y, icon[0]);
    }

    virtual void eat(int** map) {
        // 필요 시 구현
    }

    virtual void print() {
        cout << name << icon
            << ":" << nItem << endl;
    }

    int getX() { return x; }
    int getY() { return y; }
};

// Human 클래스

enum Direction 
{
    Left = 75,
    Right = 77,
    Up = 72,
    Down = 80
};

class Human : public Monster {
public:
    Human(string n = "미래인류",
        string i = "@",
        int px = 0,
        int py = 0)
        : Monster(n, i, px, py) {
    }

    virtual ~Human() {
        cout << "[Human]";
    }

    int getDirKey() {
        return getche() == 224 ? getche() : 0;
    }

    virtual void move(int** map,
        int maxx,
        int maxy) {

        if (kbhit()) {

            char ch = getDirKey();

            if (ch == Left) x--;
            else if (ch == Right) x++;
            else if (ch == Up) y--;
            else if (ch == Down) y++;
            else return;

            clip(maxx, maxy);
        }
    }
};

// Tuman 클래스

class Tuman : public Human 
{
public:
    Tuman(string n = "사람",
        string i = "@",
        int px = 0,
        int py = 0)
        : Human(n, i, px, py) {
    }

    virtual ~Tuman() {
        cout << "[Tuman]";
    }

    // 입력 키에 따라 이동
    void moveHuman(int** map,
        int maxx,
        int maxy,
        char ch) {

        // 왼쪽 플레이어 : asdw
        if (ch == 'a') x--;
        else if (ch == 'd') x++;
        else if (ch == 'w') y--;
        else if (ch == 's') y++;

        // 오른쪽 플레이어 : 화살표
        else if (ch == Left) x--;
        else if (ch == Right) x++;
        else if (ch == Up) y--;
        else if (ch == Down) y++;

        else return;

        clip(maxx, maxy);

        nItem++; // 이동 시 점수 증가 예시
    }
};

// MonsterWorld 클래스


class MonsterWorld 
{
    Canvas canvas;

    Monster* pMon[100];

    int nMon;
    int xMax, yMax;

public:
    MonsterWorld(int w = 40, int h = 20)
        : canvas(w, h) {

        nMon = 0;

        xMax = w;
        yMax = h;
    }

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++)
            delete pMon[i];
    }

    void add(Monster* m) {
        pMon[nMon++] = m;
    }

    void draw() {
        canvas.clear();

        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(&canvas);

        canvas.print("Monster World");
    }

    void play() {

        int count = 0;

        while (1) {

            // 일반 몬스터 이동
            for (int k = 0; k < nMon - 2; k++)
                pMon[k]->move(nullptr,
                    xMax, yMax);

            // 키 입력
            if (kbhit()) {

                unsigned char ch = getche();

                // 화살표 키
                if (ch == 224) {

                    ch = getche();

                    ((Tuman*)pMon[nMon - 1])
                        ->moveHuman(
                            nullptr,
                            xMax,
                            yMax,
                            ch
                        );
                }

                // asdw 키
                else {

                    ((Tuman*)pMon[nMon - 2])
                        ->moveHuman(
                            nullptr,
                            xMax,
                            yMax,
                            ch
                        );
                }
            }

            draw();

            cout << endl;
            cout << "전체 이동 횟수 : "
                << count++ << endl;

            for (int i = 0; i < nMon; i++)
                pMon[i]->print();

            Sleep(100);
        }
    }
};

// main

int main() {

    srand((unsigned)time(NULL));

    MonsterWorld game(40, 20);

    // 일반 몬스터 추가
    game.add(new Monster(
        "좀비", "Z",
        rand() % 40,
        rand() % 20));

    game.add(new Monster(
        "뱀파이어", "V",
        rand() % 40,
        rand() % 20));

    game.add(new Monster(
        "어쩌다귀신", "G",
        rand() % 40,
        rand() % 20));

    // 왼쪽 플레이어 (asdw)
    game.add(new Tuman(
        "왼쪽사람",
        "좌",
        rand() % 40,
        rand() % 20));

    // 오른쪽 플레이어 (화살표)
    game.add(new Tuman(
        "오른쪽사람",
        "우",
        rand() % 40,
        rand() % 20));

    game.play();

    return 0;
}