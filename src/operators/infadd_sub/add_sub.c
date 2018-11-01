/*
** EPITECH PROJECT, 2018
** operators
** File description:
** operators
*/

#include "all.h"
#include "number_manager.h"

number_t *add(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result;

    (void)all;
    if (a->neg == b->neg) {
        result = called_add(a, b, base);
        result->neg = a->neg;
    }
    if ((a->neg == 1 || b->neg == 1) && a->neg != b->neg)
        result = called_sub(a, b, base);
    free_number(a);
    free_number(b);
    return (clear_zero(result, base));
}

number_t *sub(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result;
    b->neg = !b->neg;
    result = add(a, b, base, all);
    return (result);
}
