#include <stdio.h>
#include "print_even.h"

#define EVEN_DECISION_NUMBER        1

void print_even_number_from_start_to_end(int start, int end)
{
    int current_number;

    for (current_number = start; current_number <= end; current_number++)
    {
        if (current_number % EVEN_DECISION_NUMBER == 1)
        {
            printf("sdf : %d\n", current_number);
        }
    }
}