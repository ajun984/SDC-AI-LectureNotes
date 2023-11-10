#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Quiz. 함수 내에서 계산한 배열을 리턴할 수 있는 방법??


// int[3] * return_array(void)
int (* return_array(void))[3]
{
    static int test_array[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };

    return test_array;
}

int main (void)
{
    int i, j;

    int (* arr)[3];

    int num1 = 1, num2 = 2, num3 = 3;
    // int 타입의 메모리 주소를 저장하는 배열 3개
    int *number_array[3] = { &num1, &num2, &num3 };

    // 행렬은 메모리상 일렬로 나열되어있음.
    // 컴파일러가 얼마씩 이동할지를 기계어로 번역
    int matrix[4][4] = {
        {  1,  2,  3,  4 },
        {  5,  6,  7,  8 },
        {  9,  10, 11, 12},
        {  13, 14, 15, 16},
    };

    // int [3] * array_pointer 형태임
    // int가 3개짜리인 녀석의 메모리 주소를 저장하는 변수
    // array_pointer는 배열이 아님
    // 12바이트 짜리 포인터 변수
    // 이중배열일 때 이렇게 씀
    int (* array_pointer)[3] = matrix;
    // == char (* array_pointer)[12] = matrix;

    for(i = 0; i < 5; i++ )
    {
        printf("*array_pointer[%d] = %d\n", i, *array_pointer[i]);
        
    }

    for(i = 0; i < 5; i++ )
    {
        printf("*array_pointer[%d][0] = %d\n", i, array_pointer[i][0]);
        
    }

    for(i = 0; i < 5; i++ )
    {
        printf("array_pointer[%d][1] = %d\n", i, array_pointer[i][1]);
        
    }

    for(i = 0; i < 5; i++ )
    {
        printf("array_pointer[%d][2] = %d\n", i, array_pointer[i][2]);
        
    }

    for(i = 0; i < 5; i++ )
    {
        
        printf("(*array_pointer)[%d] = %d\n", i, (*array_pointer)[i]);
    }

    arr = return_array();

    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 3 ; j++)
        {
            printf("arr[%d][%d] = %d\n",i,j,arr[i][j]);
        }
    }
    return 0;
}
