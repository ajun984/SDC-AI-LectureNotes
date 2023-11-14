#include <stdio.h>

int main()
{
    int num1;
    printf("정수를 입력하세요 :");
    scanf("%d", &num1);

    int num2;
    printf("정수를 입력하세요 :");
    scanf("%d", &num2);

    printf("결과 값은 : %d\n", num1 << num2);

    return 0;
}