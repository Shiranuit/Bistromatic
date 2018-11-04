/*
** EPITECH PROJECT, 2018
** number_manager
** File description:
** function to help with number struct
*/

#include "all.h"
#include <stdlib.h>

number_t *create_number(char *str, int len, int neg, int free)
{
    number_t *num = malloc(sizeof(number_t));

    num->str = str;
    num->origin = str;
    num->len = len;
    num->free = free;
    num->neg = neg;
    return (num);
}

void *free_number(number_t *a)
{
    if (!a || a->free < 1)
        return (0);
    if (a->free > 1)
        free(a->origin);
    if (a->free >= 1)
        free(a);
    return (0);
}

number_t *clear_zero(number_t *a, base_t *base)
{
    int pos = -1;

    while (a->str[++pos] == base->base[0]);
    if (a->len - pos > 1) {
        a->str = a->str + pos;
        a->len = a->len - pos;
    } else {
        a->str[a->len - 2] = base->base[0];
        a->str[a->len - 1] = '\0';
        a->str = a->str + a->len - 2;
        a->len = 2;
    }
    return (a);
}

number_t *string_to_number(char **str, base_t *base, all_t *all)
{
    int index = 0;
    char *new_str;

    while ((*str)[index] && base_to_int((*str)[index], base) > -1)
        index++;
    if (base_to_int((*str)[index], base) == -1)
        return (exception(SYNTAX_ERROR_MSG, all));
    new_str = malloc(sizeof(char) * (index + 1));
    for (int i = 0; i < index; i++)
        new_str[i] = (*str)[i];
    new_str[index] = '\0';
    move(str, index);
    return (clear_zero(create_number(new_str, index + 1, 0, 2), base));
}

int get_num(number_t *a, int pos, base_t *base)
{
    int index = a->len - 2 - pos;

    if (index < 0 || index > a->len - 2)
        return (0);
    return (base_to_int(a->str[index], base));
}
