/*
** EPITECH PROJECT, 2018
** min_max
** File description:
** min max functions
*/

#include "all.h"
#include <stdlib.h>

number_t *called_mn(number_t *a, number_t *b, base_t *base)
{
    for (int i = a->len - 1; i > -1; i--) {
        if (get_num(a, i, base) < get_num(b, i, base))
            return (a);
        if (get_num(a, i, base) > get_num(b, i, base))
            return (b);
    }
    return (a);
}

number_t *called_mx(number_t *a, number_t *b, base_t *base)
{
    for (int i = a->len; i > -1; i--) {
        if (get_num(a, i, base) > get_num(b, i, base))
            return (a);
        if (get_num(a, i, base) < get_num(b, i, base))
            return (b);
    }
    return (a);
}

number_t *called_min(number_t *a, number_t *b, int use_sign, base_t *base)
{
    clear_zero(a, base);
    clear_zero(b, base);

    if (a->neg == 1 && b->neg == 0 && use_sign == 1)
        return (a);
    if (a->neg == 0 && b->neg == 1 && use_sign == 1)
        return (b);
    if (a->len < b->len)
        return (a);
    if (a->len > b->len)
        return (b);
    return (called_mn(a, b, base));
}

number_t *called_max(number_t *a, number_t *b, int use_sign, base_t *base)
{
    clear_zero(a, base);
    clear_zero(b, base);

    if (a->neg == 0 && b->neg == 1 && use_sign == 1)
        return (a);
    if (a->neg == 1 && b->neg == 0 && use_sign == 1)
        return (b);
    if (a->len > b->len)
        return (a);
    if (a->len < b->len)
        return (b);
    return (called_mx(a, b, base));
}
