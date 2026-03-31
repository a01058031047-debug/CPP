#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void randomMap(int map[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            map[i][j] = rand() % 2;
        }
    }
}

void printMap(int map[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    int heckmap(int map[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        bool same = true;
        for (int j = 1; j < 5; j++) 
        {
            if (map[i][j] != map[i][0]) 
            {
                same = false;
                break;
            }
        }
        if (same) 
        {
            cout << "Row " << i << " is all " << map[i][0] << endl;
        }
    }
}

    for (int j = 0; j < 5; j++) 
    {
        bool same = true;
        for (int i = 1; i < 5; i++) 
        {
            if (map[i][j] != map[0][j]) 
            {
                same = false;
                break;
            }
        }
        if (same) 
        {
            cout << "Column " << j << " is all " << map[0][j] << endl;
        }
    }

    bool same = true;
    for (int i = 1; i < 5; i++) 
    {
        if (map[i][i] != map[0][0]) 
        {
            same = false;
            break;
        }
    }
    if (same)
    {
        cout << "Main diagonal is all " << map[0][0] << endl;
    }

    same = true;
    for (int i = 1; i < 5; i++) 
    {
        if (map[i][4 - i] != map[0][4]) 
        {
            same = false;
            break;
        }
    }
    if (same) 
    {
        cout << "Anti-diagonal is all " << map[0][4] << endl;
    }
}

int main() 
{
    int map[5][5];

    srand(time(0));

    randomMap(map);
    printMap(map);
    cout << "-------------------" << endl;
    checkMap(map);

    return 0;
}