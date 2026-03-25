#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int p, n, b;
    cin >> p >> n >> b;

    int bullet[100], used[100] = {0};

    for (int i = 0; i < b; ) {
        int r = rand() % n;
        if (!used[r]) 
        {
            used[r] = 1;
            bullet[i++] = r;
        }
    }

    int pos = rand() % n, player = 1;

    while (b) {
        for (int i = 0; i < b; i++) 
        {
            if (bullet[i] == pos) 
            {
                cout << player << "번 맞음\n";
                bullet[i] = bullet[--b];
                break;
            }
        }
        pos = (pos + 1) % n;
        player = player % p + 1;
    }
}