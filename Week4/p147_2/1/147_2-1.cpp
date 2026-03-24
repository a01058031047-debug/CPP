#include <stdio.h>

int reverse(int n)
{
    int rev = 0;

    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }

    return rev;
}

int main()
{
    int num;
    int result;

    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    result = reverse(num);

    printf("result = %d\n", result);
}