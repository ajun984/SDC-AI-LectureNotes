#include <stdio.h>
#include "print_even.h"

void print_even_number_from_start_to_end(int start, int end)
{
    int current_number;

    for (current_number = start; current_number <= end; current++)
    {
        if (current_number % EVEN_DECISION_NUMBER ==0)
        {
            printf("sdf : %d\n", current_number);
        }
    }
}