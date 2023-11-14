#include <stdio.h>


int main()
{
    float num1;

    printf("실수를 입력하세요 :");
    scanf("%f", &num1);

    int num2;

    printf("정수를 입력하세요 :");
    scanf("%d", &num2);


    printf("%f\n", num1 * num2);

    return 0;

}