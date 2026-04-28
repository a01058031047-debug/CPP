#pragma once
#include "Canvas.h"
#include <iostream>
#include <string>

using namespace std;

class Monster 
{
    string name, icon;
    int x, y, nItem;
    int nEnergy; // (1) 에너지 속성 추가

public:
    // (2) 생성자: 멤버 초기화 리스트를 사용하여 nEnergy를 100으로 초기화
    Monster(string n = "나괴물", string i = "*", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}

    ~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~" << endl; }

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    // (3) eat() 함수 수정
    void eat(int map[40][40])
    {
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8; // 아이템을 먹으면 에너지 8 증가
        } else {
            nEnergy -= 1; // 아이템을 못 먹으면 에너지 1 감소
            if (nEnergy < 0) nEnergy = 0; // 최솟값은 0
        }
    }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int map[40][40], int maxx, int maxy)
    {
        switch (rand() % 8) {
            case 0: y--; break;
            case 1: x++; y--; break;
            case 2: x++; break;
            case 3: x++; y++; break;
            case 4: y++; break;
            case 5: x--; y++; break;
            case 6: x--; break;
            case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }

    // (4) print() 함수 수정: 에너지 레벨 출력 추가
    void print()
    { 
        cout << "\t" << name << icon << " E:" << nEnergy << endl; 
    }
};