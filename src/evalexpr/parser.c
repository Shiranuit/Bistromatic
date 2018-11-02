/*
** EPITECH PROJECT, 2018
** parser
** File description:
** parser
*/

#include "all.h"
#include <stdlib.h>

operator_t *readoplevel(char **str, int lvl, operator_t **ls, all_t *all)
{
    operator_t *op;

    skip_space(str);
    if ((*str)[0] == all->ops[1] && lvl == 0) {
        all->paranthesis = all->paranthesis - 1;
        if (all->paranthesis < 0)
            exception(SYNTAX_ERROR_MSG, all);
        return (0);
    }
    for (int i = 0; ls[i]; i++) {
        op = ls[i];
        if (op->level == lvl)
            if (my_strncmp(*str, op->op, op->length) == 1) {
                move(str, op->length);
                return (op);
            }
        if (op->level > lvl)
            return (0);
    }
    return (0);
}

number_t *parse_expression(char **str, int lvl, operator_t **ls, all_t *all)
{
    number_t *left = 0;
    number_t *right = 0;
    number_t *result = 0;
    operator_t *op = 0;

    if (lvl + 1 <= OPLVMAX)
        left = parse_expression(str, lvl + 1, ls, all);
    else
        left = parse_unm(str, ls, all);
    while ((op = readoplevel(str, lvl, ls, all)) && *(all->exit) == -1) {
         right = parse_expression(str, lvl + 1, ls, all);
        if (*(all->exit) > -1)
            return (free_number2(left, right));
        result = op->func(left, right, all->base, all);
        if (*(all->exit) == -1)
            left = result;
    }
    if (*(all->exit) > -1)
        return (free_number2(left, right));
    return (left);
}

number_t *parse_unm(char **str, operator_t **list, all_t *all)
{
    if (*(all->exit) > -1)
        return (0);
    skip_space(str);
    if ((*str)[0] == '-') {
        move(str, 1);
        return (unm(parse_unm(str, list, all), all));
    }
    return (parse_val(str, list, all));
}

number_t *parse_val(char **str, operator_t **list, all_t *all)
{
    number_t *value;

    if (readc(str) == all->ops[OP_OPEN_PARENT_IDX]) {
        all->paranthesis = all->paranthesis + 1;
        value = parse_expression(str, 0, list, all);
        if (readc(str) == all->ops[OP_CLOSE_PARENT_IDX])
            return (value);
        free_number(value);
        return (exception(SYNTAX_ERROR_MSG, all));
    }
    move(str, -1);
    if (base_to_int((*str)[0], all->base) == -1)
        return (exception(SYNTAX_ERROR_MSG, all));
    if ((*str)[0] == '\0')
        return (exception(SYNTAX_ERROR_MSG, all));
    return (string_to_number(str, all->base));
}

number_t *parse(char **str, all_t *all)
{
    operator_t **list = init_oplist(all->ops);
    number_t *result = parse_expression(str, 0, list, all);

    for (int i = 0; list[i] != 0; i++)
        free(list[i]);
    free(list);
    return (result);
}
