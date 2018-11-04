/*
** EPITECH PROJECT, 2018
** check params
** File description:
** check errors in parameter
*/

#include "all.h"

void *error_params(char a, char b, all_t *all)
{
    if (a == b)
        return (exception(SYNTAX_ERROR_MSG, all));
    return (0);
}

void check_base(base_t *base, all_t *all)
{
    int i = 0;
    int j;

    while (base->base[i]) {
        j = i + 1;
        while (base->base[j + 1]) {
           error_params(base->base[j], base->base[i], all);
            j++;
        }
        i++;
    }
}

void check_operator(char *ops, all_t *all)
{
    int i = 0;
    int j;

    while (ops[i]) {
        j = i + 1;
        while (ops[j]) {
            error_params(ops[j], ops[i], all);
            j++;
        }
        i++;
    }
}

void check_base_in_operator(base_t *base, char *ops, all_t *all)
{
    int i = 0;
    int j;

    while (base->base[i]) {
        j = i;
        while (ops[j]) {
            error_params(ops[j], base->base[i], all);
            j++;
        }
        i++;
    }
}

void check_params(base_t *base, char *ops, all_t *all)
{
    check_base(base, all);
    check_operator(ops, all);
    check_base_in_operator(base, ops, all);
}