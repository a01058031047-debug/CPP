
//(1) Monster 클래스 수정
#pragma once
#include <iostream>
using namespace std;

class Monster 
{
protected:
    string name;
    string icon;
    int x, y;
    int nEnergy;

    static int count;   // 전체 몬스터 수

public:
    Monster(string n = "몬스터", string i = "M", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nEnergy(100) 
    {
        count++;
    }

    virtual ~Monster() {
        count--;
    }

    virtual void move(int** map, int maxx, int maxy) 
    {
        int dx = (rand() % 3) - 1;
        int dy = (rand() % 3) - 1;

        x = (x + dx + maxx) % maxx;
        y = (y + dy + maxy) % maxy;

        eat(map);
        nEnergy--;  // 움직이면 에너지 감소
    }

    virtual void eat(int** map) 
    {
        if (map[y][x] > 0) {
            map[y][x] = 0;
            nEnergy += 20;
        }
    }

    virtual void draw(class Canvas& canvas);

    virtual void print() 
    {
        cout << name << " (" << x << "," << y << ") "
             << "Energy=" << nEnergy << endl;
    }

    int getEnergy() { return nEnergy; }

    static void printCount() 
    {
        cout << "현재 몬스터 수 = " << count << endl;
    }
};

int Monster::count = 0;

//(2) MonsterWorld 클래스 수정
void checkStarvation() 
{
    for (int i = 0; i < nMon; ) 
    {
        if (pMon[i]->getEnergy() <= 0) 
        {
            delete pMon[i];

            // 마지막 몬스터를 앞으로 이동
            pMon[i] = pMon[nMon - 1];
            nMon--;

            cout << "Monster 하나가 굶어 죽습니다\n";
        }
        else 
        {
            i++;
        }
    }
}

//(3) play() 함수 수정
void play(int maxwalk, int wait) 
{
    print();
    getchar();

    for (int i = 0; i < maxwalk; i++) 
    {
        for (int k = 0; k < nMon; k++)
            pMon[k]->move(world.Data(), xMax, yMax);

        nMove++;

        checkStarvation();

        print();

        Monster::printCount();

        if (isDone()) break;

        Sleep(wait);
    }
}

//(4) print()에도 출력 추가 (선택 but 문제 요구 반영)
void print() 
{
    canvas.clear(".");

    for (int y = 0; y < yMax; y++)
        for (int x = 0; x < xMax; x++)
            if (Map(x, y) > 0)
                canvas.draw(x, y, "■");

    for (int i = 0; i < nMon; i++)
        pMon[i]->draw(canvas);

    canvas.print("[ Monster World (Dynamic World) ]");

    cerr << "전체 이동 횟수 = " << nMove << endl;
    cerr << "남은 아이템 수 = " << countItems() << endl;

    for (int i = 0; i < nMon; i++)
        pMon[i]->print();

    Monster::printCount();   // ⭐ 추가
}