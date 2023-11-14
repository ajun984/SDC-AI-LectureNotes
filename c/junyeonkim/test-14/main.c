#include <stdio.h>

int main()
{
    int num1;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &num1);

    int num2;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &num2);
    (num1 == num2) ? printf("같습니다.\n") :
    
    (num1 > num2) ? printf("큰 수는 %d\n", num1) 
            : printf("큰 수는 : %d\n", num2);

}

