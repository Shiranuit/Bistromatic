/*
** EPITECH PROJECT, 2018
** init_struct
** File description:
** init_struct
*/

#include "all.h"
#include "unittest.h"

base_t *init_base(char *base_v)
{
    base_t *base = malloc(sizeof(base_t));

    base->len = my_strlen(base_v) - 1;
    base->base = base_v;
}

all_t *init_all(char *expr, base_t *base)
{
    all_t *all = malloc(sizeof(all_t));
    int exitcode = -1;

    all->origin = expr;
    all->base = base;
    all->paranthesis = 0;
    all->ops = base->base;
    all->exit = &exitcode;
}