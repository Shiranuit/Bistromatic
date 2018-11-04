/*
** EPITECH PROJECT, 2018
** logic_operator
** File description:
** logic operator
*/

#include "all.h"

number_t *and(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int cmp = !equal_zero(a, base) && !equal_zero(b, base);

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}

number_t *or(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int cmp = !equal_zero(a, base) || !equal_zero(b, base);

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}
