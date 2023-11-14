#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "print_random.h"
#include "random_generator.h"

void print_random_number(int count)
{
    int loop;

    const int min = 3;
    const int max = 20;

    srand(time(NULL));

    printf("3 - 20 랜덤번호 출력 :\n");
    for (loop = 0; loop < count; loop++)
    {
        printf("%3d", generate_random(3, 20));
    }
}