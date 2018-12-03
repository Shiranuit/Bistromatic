/*
** EPITECH PROJECT, 2018
** convert_base
** File description:
** convert_base
*/

#include "all.h"
#include <stdio.h>

char int_to_base(int a, base_t *base)
{
    return (base->base[a]);
}

int base_to_int(char a, base_t *base)
{
    int i = 0;

    for (; base->base[i] != a && base->base[i]; i++);
    return (i > base->len - 1 ? -1 : i);
}
