#include <stdio.h>
 
void seperate(float n);

int main(void)
{
    float n;

    printf("실수를 입력하세요 :\n");
    scanf("%f", &n);

    seperate(n);
}

void seperate(float n)
{
    printf("결과 :\n");

    printf("%g = %d + %g\n", n, (int)n, n - (int)n);
}