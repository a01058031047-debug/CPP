#include <stdio.h>

int reverse(int);

int main()
{
    int num, result;

    scanf("%d", &num);

    result = reverse(num);

    printf("%d", result);
}

int reverse(int n)
{
    int r = 0;

    while (n > 0)
    {
        r = r * 10 + n % 10;
        n = n / 10;
    }

    return r;
}