/*
** EPITECH PROJECT, 2018
** compare_operator
** File description:
** compare operator
*/

#include "all.h"

number_t *equal(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int cmp = struct_cmp(a, b, base) == 0;

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}

number_t *greater_than(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int cmp = struct_cmp(a, b, base) == 1;

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}

number_t *less_than(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int cmp = struct_cmp(a, b, base) == -1;

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}

number_t *greater_or_equal(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int compare = struct_cmp(a, b, base);
    int cmp = compare == 1 || compare == 0;

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}

number_t *less_or_equal(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int compare = struct_cmp(a, b, base);
    int cmp = compare == -1 || compare == 0;

    (void)all;
    free_number(a);
    free_number(b);
    return (cmp ? create_one(base) : create_zero(base));
}
