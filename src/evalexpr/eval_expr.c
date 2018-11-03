/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** eval_expr
*/

#include "all.h"
#include <stdlib.h>

void free_list(operator_t **list)
{
    for (int i = 0; list[i]; i++)
        free(list[i]);
    free(list);
}

void init_var_expr(base_t *base, all_t *all, char *base_v, char *expr)
{
    operator_t **list = init_oplist(all->ops);
    for (int i = 0; list[i]; i++) {
        if (my_strncmp(list[i]->op, expr, list[i]->length) == 1 && i != 1) {
            exception(SYNTAX_ERROR_MSG, all);
            free_list(list);
            free(base);
            free(expr);
            free(all);
            exit(84);
        }
    }
    free_list(list);
    base->len = my_strlen(base_v) - 1;
    base->base = base_v;
    all->origin = expr;
    all->base = base;
    all->paranthesis = 0;
}

number_t *eval_expr(char *base_v, char *ops, char *expr, base_t *base)
{
    all_t *all = malloc(sizeof(all_t));
    number_t *result;
    int exitcode = -1;

    all->ops = ops;
    all->exit = &exitcode;
    init_var_expr(base, all, base_v, expr);
    result = parse(&expr, all);
    free(all->origin);
    free(all);
    if (exitcode > -1) {
        free_number(result);
        exit(exitcode);
    }
    return (result);
}
