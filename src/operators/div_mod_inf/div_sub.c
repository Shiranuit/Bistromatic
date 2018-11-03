/*
** EPITECH PROJECT, 2018
** div_sub
** File description:
** specific substraction
*/

#include "all.h"

void div_sub(number_t *a, number_t *b, base_t *base, int mv)
{
    int va = 0;
    int vb = 0;
    int car = 0;
    int sum = 0;

    for (int i = 0; i < a->len - 1; i++) {
        va = get_num(a, i, base);
        vb = get_num(b, i - mv, base);
        sum = (va >= vb + car ? va : va + base->len) - (vb + car);
        car = (va >= vb + car) ? 0 : 1;
        a->str[a->len - 2 - i] = int_to_base(sum, base);
    }
}
