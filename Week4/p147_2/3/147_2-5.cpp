#include <stdio.h>
#include "reverse.h"

int main()
{
    int num, result;

    scanf("%d", &num);

    result = reverse(num);

    printf("%d\n", result);

    return 0;
}