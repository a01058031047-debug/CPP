// (1) 대각선으로만 이동하는 Smombi 클래스 추가

class Smombi : public Monster 
{
public:
    Smombi(string n = "스몸비", string i = "X",
        int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }

    ~Smombi() { cout << " Smombi"; }

    void move(int** map, int maxx, int maxy) {

        int dir = rand() % 4;

        // 대각선 이동
        if (dir == 0) {
            x--; y--;
        }
        else if (dir == 1) {
            x++; y--;
        }
        else if (dir == 2) {
            x--; y++;
        }
        else {
            x++; y++;
        }

        clip(maxx, maxy);
        eat(map);
    }
};

// (2) 방향을 바꾸는 슈퍼 강시 Siangshi 클래스

class Siangshi : public Jiangshi 
{
    int cnt;

public:
    Siangshi(string n = "슈퍼강시",
        string i = "S",
        int x = 0, int y = 0,
        bool bH = true)
        : Jiangshi(n, i, x, y, bH) {

        cnt = 0;
    }

    ~Siangshi() 
    {
        cout << " Siangshi";
    }

    void move(int** map, int maxx, int maxy) 
    {

        cnt++;

        // 5번 움직일 때마다 방향 전환
        if (cnt % 5 == 0)
            bHori = !bHori;

        int dir = rand() % 2;
        int jump = rand() % 2 + 1;

        if (bHori)
            x += ((dir == 0) ? -jump : jump);
        else
            y += ((dir == 0) ? -jump : jump);

        clip(maxx, maxy);
        eat(map);
    }
};

// (3) 자신만의 몬스터 클래스 만들기

class FastVampire : public Vampire 
{
public:

    FastVampire(string n = "빠른뱀파이어",
        string i = "F",
        int x = 0, int y = 0)
        : Vampire(n, i, x, y) {
    }

    ~FastVampire() 
    {
        cout << " FastVampire";
    }

    void move(int** map, int maxx, int maxy) 
    {

        int dir = rand() % 4;

        if (dir == 0)
            x -= 2;
        else if (dir == 1)
            x += 2;
        else if (dir == 2)
            y -= 2;
        else
            y += 2;

        clip(maxx, maxy);
        eat(map);
    }
};

// (4) main() 함수에서 테스트

#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
    srand((unsigned int)time(NULL));

    int w = 16, h = 8;

    MonsterWorld game(w, h);

    // 기존 몬스터
    game.add(new Zombie("허접좀비", "$",
        rand() % w, rand() % h));

    game.add(new Vampire("뱀파이어", "*",
        rand() % w, rand() % h));

    game.add(new KGhost("처녀귀신", "♥",
        rand() % w, rand() % h));

    game.add(new Jiangshi("강시", "↔",
        rand() % w, rand() % h, true));

    // 추가 몬스터
    game.add(new Smombi("스몸비", "X",
        rand() % w, rand() % h));

    game.add(new Siangshi("슈퍼강시", "S",
        rand() % w, rand() % h, true));

    game.add(new FastVampire("빠른뱀파이어", "F",
        rand() % w, rand() % h));

    game.play(500, 10);

    printf("------게임 종료------\n");
}

// 최종코드 

#pragma once
#include "Monster.h"

// ---------------- Zombie ----------------
class Zombie : public Monster 
{
public:
    Zombie(string n = "허접좀비",
        string i = "$",
        int x = 0,
        int y = 0)
        : Monster(n, i, x, y) {
    }

    ~Zombie() {
        cout << " Zombie";
    }
};

// ---------------- Vampire ----------------
class Vampire : public Monster 
{
public:
    Vampire(string n = "뱀파이어",
        string i = "*",
        int x = 0,
        int y = 0)
        : Monster(n, i, x, y) {
    }

    ~Vampire() {
        cout << " Vampire";
    }

    void move(int** map, int maxx, int maxy) 
    {

        int dir = rand() % 4;

        if (dir == 0)
            x--;
        else if (dir == 1)
            x++;
        else if (dir == 2)
            y--;
        else
            y++;

        clip(maxx, maxy);
        eat(map);
    }
};

// ---------------- KGhost ----------------
class KGhost : public Monster 
{
public:
    KGhost(string n = "처녀귀신",
        string i = "♥",
        int x = 0,
        int y = 0)
        : Monster(n, i, x, y) {
    }

    ~KGhost() {
        cout << " KGhost";
    }

    void move(int** map, int maxx, int maxy) 
    {

        x = rand() % maxx;
        y = rand() % maxy;

        clip(maxx, maxy);
        eat(map);
    }
};

// ---------------- Jiangshi ----------------
class Jiangshi : public Monster 
{

protected:
    bool bHori;

public:
    Jiangshi(string n = "대륙강시",
        string i = "↔",
        int x = 0,
        int y = 0,
        bool bH = true)
        : Monster(n, i, x, y), bHori(bH) {
    }

    ~Jiangshi() 
    {
        cout << " Jiangshi";
    }

    void move(int** map, int maxx, int maxy) 
    {

        int dir = rand() % 2;
        int jump = rand() % 2 + 1;

        if (bHori)
            x += ((dir == 0) ? -jump : jump);
        else
            y += ((dir == 0) ? -jump : jump);

        clip(maxx, maxy);
        eat(map);
    }
};

// ======================================================
// (1) Smombi : 대각선 이동 몬스터
// ======================================================

class Smombi : public Monster 
{
public:

    Smombi(string n = "스몸비",
        string i = "X",
        int x = 0,
        int y = 0)
        : Monster(n, i, x, y) {
    }

    ~Smombi() 
    {
        cout << " Smombi";
    }

    void move(int** map, int maxx, int maxy) 
    {

        int dir = rand() % 4;

        if (dir == 0) 
        {
            x--;
            y--;
        }
        else if (dir == 1) 
        {
            x++;
            y--;
        }
        else if (dir == 2) 
        {
            x--;
            y++;
        }
        else 
        {
            x++;
            y++;
        }

        clip(maxx, maxy);
        eat(map);
    }
};

// ======================================================
// (2) Siangshi : 방향 전환 가능한 슈퍼 강시
// ======================================================

class Siangshi : public Jiangshi 
{

    int cnt;

public:

    Siangshi(string n = "슈퍼강시",
        string i = "S",
        int x = 0,
        int y = 0,
        bool bH = true)
        : Jiangshi(n, i, x, y, bH) 
        {

        cnt = 0;
    }

    ~Siangshi() 
    {
        cout << " Siangshi";
    }

    void move(int** map, int maxx, int maxy) 
    {

        cnt++;

        // 5번마다 이동 방향 변경
        if (cnt % 5 == 0)
            bHori = !bHori;

        int dir = rand() % 2;
        int jump = rand() % 2 + 1;

        if (bHori)
            x += ((dir == 0) ? -jump : jump);
        else
            y += ((dir == 0) ? -jump : jump);

        clip(maxx, maxy);
        eat(map);
    }
};

// ======================================================
// (3) 사용자 정의 몬스터 : FastVampire
// ======================================================

class FastVampire : public Vampire 
{

public:

    FastVampire(string n = "빠른뱀파이어",
        string i = "F",
        int x = 0,
        int y = 0)
        : Vampire(n, i, x, y) {
    }

    ~FastVampire() {
        cout << " FastVampire";
    }

    void move(int** map, int maxx, int maxy) 
    {

        int dir = rand() % 4;

        if (dir == 0)
            x -= 2;
        else if (dir == 1)
            x += 2;
        else if (dir == 2)
            y -= 2;
        else
            y += 2;

        clip(maxx, maxy);
        eat(map);
    }
};

// MonsterWorldGame.cpp

#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
    srand((unsigned int)time(NULL));

    int w = 16;
    int h = 8;

    MonsterWorld game(w, h);

    // 기존 몬스터
    game.add(new Zombie("허접좀비", "$",
        rand() % w, rand() % h));

    game.add(new Vampire("뱀파이어", "*",
        rand() % w, rand() % h));

    game.add(new KGhost("처녀귀신", "♥",
        rand() % w, rand() % h));

    game.add(new Jiangshi("가로강시", "↔",
        rand() % w, rand() % h, true));

    game.add(new Jiangshi("세로강시", "↕",
        rand() % w, rand() % h, false));

    // 추가 몬스터들
    game.add(new Smombi("스몸비", "X",
        rand() % w, rand() % h));

    game.add(new Siangshi("슈퍼강시", "S",
        rand() % w, rand() % h, true));

    game.add(new FastVampire("빠른뱀파이어", "F",
        rand() % w, rand() % h));

    game.play(500, 10);

    printf("\n------ 게임 종료 ------\n");
}