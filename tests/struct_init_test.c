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
    return (base);
}

all_t *init_all(char *expr, base_t *base, int *exit)
{
    all_t *all = malloc(sizeof(all_t));

    all->origin = expr;
    all->base = base;
    all->paranthesis = 0;
    all->base = base;
    all->ops = "()+-*/%";
    all->exit = exit;
    return (all);
}
