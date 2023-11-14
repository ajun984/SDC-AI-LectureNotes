#include <stdio.h>

int main(void)

{
	int num1;
    printf("숫자를 입력하세요 :");
    scanf("%d", &num1);
	
    int num2;
    printf("숫자를 입력하세요 :");
    scanf("%d", &num2);
	
	int and_data = num1 & num2;
	int or_data = num1 | num2;
	int xor_data = num1 ^ num2;
    int num1_not_data = ~num1;
    int num2_not_data = ~num2;

	printf("and_data : %d \n", and_data );
	printf("or_data : %d \n", or_data );
	printf("xor_data : %d \n", xor_data );
    printf("num1의 not_data : %d \n", num1_not_data);
    printf("num2의 not_data : %d \n", num2_not_data);    

	return 0;
}
