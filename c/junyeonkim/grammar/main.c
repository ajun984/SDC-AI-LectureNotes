#include <stdio.h>

#include "print_random.h"
#include "print_even.h"


int main(void)
{
    const int random_number_count = 18;
    const int start = 3;
    const int end = 20;

    print_even_number_from_start_to_end(start, end);

    printf("sdfsdf\n");

    print_random_number(random_number_count);

    return 0;
}