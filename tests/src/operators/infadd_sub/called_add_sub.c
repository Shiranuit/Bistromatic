/*
** EPITECH PROJECT, 2018
** add_sub
** File description:
** add and sub functions
*/

#include "all.h"
#include <stdlib.h>
#include <stdio.h>

number_t *called_add(number_t *a, number_t *b, base_t *base)
{
    int max_len = a->len > b->len ? a->len : b->len;
    char *new_str = malloc(sizeof(char) * (max_len + 1));
    int c = 0;
    int sum = 0;

    for (int i = 0;  i < max_len; i++) {
        sum = get_num(a, i, base);
        sum += get_num(b, i, base) + c;
        c = sum > base->len - 1 ? 1 : 0;
        sum = sum > base->len - 1 ? sum - base->len : sum;
        new_str[max_len - i - 1] = int_to_base(sum, base);
    }
    new_str[max_len] = '\0';
    return (create_number(new_str, max_len + 1, 0, 2));
}

number_t *called_sub(number_t *a, number_t *b, base_t *base)
{
    number_t *mx = called_max(a, b, 0, base);
    number_t *mn = called_min(a, b, 0, base);
    char *new_str = malloc(sizeof(char) * mx->len);
    int va = 0;
    int vb = 0;
    int car = 0;
    int sum = 0;

    for (int i = 0; i < mx->len - 1; i++) {
        va = get_num(mx, i, base);
        vb = get_num(mn, i, base);
        sum = (va >= vb + car ? va : va + base->len) - (vb + car);
        car = (va >= vb + car) ? 0 : 1;
        new_str[mx->len - 2 - i] = int_to_base(sum, base);
    }
    new_str[mx->len - 1] = '\0';
    return (create_number(new_str, mx->len, mx->neg, 2));
}
