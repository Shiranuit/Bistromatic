/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** mod.c
*/

#include "all.h"

number_t *do_mod(number_t *a, number_t *b, base_t *base)
{
    int mv = a->len - b->len - 1;

    mv = struct_ncmp(a, b, base, mv + 1) == 1 ? mv + 1 : mv;
    while (mv > -1) {
        if (struct_ncmp(a, b, base, mv) == -1) {
            mv--;
        }
        if (mv > -1 && struct_ncmp(a, b, base, mv) >= 0) {
            div_sub(a, b, base, mv);
        }
    }
    return (a);
}

number_t *modinf(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result;
    int cmp = struct_cmp(a, b, base);

    if (equal_zero(b, base))
        return (exception(ERROR_MSG, all));
    if (cmp == 0)
        return (create_zero(base));
    result = copy_number(do_mod(a, b, base));
    result->neg = b->neg;
    free_number2(a, b);
    return (result);
}