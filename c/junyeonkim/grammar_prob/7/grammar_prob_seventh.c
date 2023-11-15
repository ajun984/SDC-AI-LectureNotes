#include "grammar_prob_seventh.h"

#include "../utility/random.h"

#define ARRAY_MAX           3

int *return_random_array_data(void)
{
    static int array[ARRAY_MAX] = { 0 };
    int i;

    for (i = 0; i < ARRAY_MAX; i++)
    {
        array[i] = generate_random(1, 10);
    }

    return array;
}