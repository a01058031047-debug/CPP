#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_X 80
#define MAX_Y 40

// 열거형 선언
enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

// 전역 변수
static int MineMapMask[MAX_Y][MAX_X];
static int MineMapLabel[MAX_Y][MAX_X];
static int nx, ny, nBomb;

// 인라인 함수
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

// 지뢰가 없는 영역을 파내는 함수
static void dig(int x, int y) {
    if (isValid(x, y) && mask(x, y) != Open) {
        mask(x, y) = Open;
        if (label(x, y) == 0) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    dig(x + i, y + j);
                }
            }
        }
    }
}

// 깃발을 꽂는 함수
static void mark(int x, int y) 
{
    if (isValid(x, y) && mask(x, y) == Hide)
        mask(x, y) = Flag;
    else if (isValid(x, y) && mask(x, y) == Flag)
        mask(x, y) = Hide; // 이미 깃발이면 다시 숨김
}

static int getBombCount() 
{
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (mask(x, y) == Flag) count++;
    return count;
}

// 화면 출력 함수 (문제 3번: 숫자 좌표 표시)
static void print() 
{
    system("cls");
    printf(" [발견: %2d / 전체: %2d]\n\n", getBombCount(), nBomb);

    // 열 번호 (가로축) 출력
    printf("    ");
    for (int x = 0; x < nx; x++) printf("%2d", x);
    printf("\n   ");
    for (int x = 0; x < nx; x++) printf("--");
    printf("\n");

    for (int y = 0; y < ny; y++) 
    {
        printf("%2d |", y); // 행 번호 (세로축) 출력
        for (int x = 0; x < nx; x++) 
        {
            if (mask(x, y) == Hide) printf(" □");
            else if (mask(x, y) == Flag) printf(" 🚩");
            else 
            {
                if (isBomb(x, y)) printf(" ※");
                else if (label(x, y) == 0) printf("  ");
                else printf("%2d", label(x, y));
            }
        }
        printf("\n");
    }
}

// 주변 지뢰 개수 계산
static int countNbrBombs(int x, int y) 
{
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isValid(xx, yy) && label(xx, yy) == Bomb) count++;
    return count;
}

// 초기화 함수 (문제 2번: 랜덤 지뢰 매설)
static void init(int total) {
    srand((unsigned int)time(NULL));
    nBomb = total;
    for (int y = 0; y < ny; y++) 
    {
        for (int x = 0; x < nx; x++) 
        {
            mask(x, y) = Hide;
            label(x, y) = 0;
        }
    }

    for (int i = 0; i < nBomb; ) 
    {
        int rx = rand() % nx;
        int ry = rand() % ny;
        if (label(rx, ry) != Bomb) 
        {
            label(rx, ry) = Bomb;
            i++;
        }
    }

    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(x, y) != Bomb)
                label(x, y) = countNbrBombs(x, y);
}

// 사용자 입력 처리 (문제 4번: "p 열 행" 방식)
static bool getPos(int& x, int& y) 
{
    char buf[128];
    printf("\n 입력(열 행) 또는 깃발(p 열 행) -> ");
    fflush(stdin);
    fgets(buf, sizeof(buf), stdin);

    if (buf[0] == 'p' || buf[0] == 'P') {
        sscanf(buf + 1, "%d %d", &x, &y);
        return true; // 깃발 모드
    } else {
        sscanf(buf, "%d %d", &x, &y);
        return false; // 파내기 모드
    }
}

static int checkDone() 
{
    int openCount = 0;
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) == Open) {
                if (isBomb(x, y)) return -1; // 실패
                openCount++;
            }
        }
    }
    return (openCount == nx * ny - nBomb) ? 1 : 0; // 성공 여부
}

void playMineSweeper(int total) 
{
    int x, y, status;
    init(total);
    do {
        print();
        bool isFlag = getPos(x, y);
        if (isValid(x, y)) {
            if (isFlag) mark(x, y);
            else dig(x, y);
        }
        status = checkDone();
    } while (status == 0);

    print();
    if (status < 0) printf("\n [실패] 지뢰가 폭발했습니다!!!\n");
    else printf("\n [성공] 모든 지뢰를 찾았습니다!!!\n");
}

int main() 
{
    int w, h, total;
    printf(" <지뢰 찾기>\n");
    printf(" 맵 가로 크기 (최대 %d): ", MAX_X); scanf("%d", &w);
    printf(" 맵 세로 크기 (최대 %d): ", MAX_Y); scanf("%d", &h);
    printf(" 매설할 지뢰 개수: "); scanf("%d", &total);

    nx = (w > MAX_X) ? MAX_X : w;
    ny = (h > MAX_Y) ? MAX_Y : h;

    playMineSweeper(total);
    return 0;
}