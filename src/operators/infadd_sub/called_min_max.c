/*
** EPITECH PROJECT, 2018
** min_max
** File description:
** min max functions
*/

#include "all.h"
#include <stdlib.h>

int struct_cmp(number_t *a, number_t *b, base_t *base)
{
    if (a->len > b->len)
        return (1);
    if (a->len < b->len)
        return (-1);
    for (int i = a->len - 1; i >= 0; i--) {
        if (get_num(a, i, base) > get_num(b, i, base))
            return (1);
        if (get_num(a, i, base) < get_num(b, i, base))
            return (-1);
    }
    return (0);
}

number_t *called_min(number_t *a, number_t *b, int use_sign, base_t *base)
{
    clear_zero(a, base);
    clear_zero(b, base);

    if (a->neg == 1 && b->neg == 0 && use_sign == 1)
        return (a);
    if (a->neg == 0 && b->neg == 1 && use_sign == 1)
        return (b);
    if (struct_cmp(a,b,base) == -1) {
        return (a);
    } else {
        return (b);
    }
}

number_t *called_max(number_t *a, number_t *b, int use_sign, base_t *base)
{
    clear_zero(a, base);
    clear_zero(b, base);

    if (a->neg == 0 && b->neg == 1 && use_sign == 1)
        return (a);
    if (a->neg == 1 && b->neg == 0 && use_sign == 1)
        return (b);
    if (struct_cmp(a,b,base) == 1) {
        return (a);
    } else {
        return (b);
    }
}
