/*
** EPITECH PROJECT, 2018
** check_number
** File description:
** check_number
*/

#include "all.h"

int equalZero(number_t *a, base_t *base)
{
    clear_zero(a, base);
    if (a->len == 2 && a->str[0] == base->base[0])
        return (1);
    return (0);
}

int equalOne(number_t *a, base_t *base)
{
    clear_zero(a, base);
    if (a->len == 2 && a->str[0] == base->base[1])
        return (1);
    return (0);
}

number_t *create_zero(base_t *base)
{
    char *new_str = malloc(sizeof(char) * 2);

    new_str[0] = int_to_base(0, base);
    new_str[1] = '\0';
    return (create_number(new_str, 2, 0, 2));
}


number_t *copy_number(number_t *a)
{
    char *new_str = malloc(sizeof(char) * a->len);

    for (int i = 0; i < a->len; i++)
        new_str[i] = a->str[i];
    return (create_number(new_str, a->len, a->neg, a->free));
}
