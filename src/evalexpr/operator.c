/*
** EPITECH PROJECT, 2018
** operator
** File description:
** operator
*/

#include "all.h"
#include <stdlib.h>

operator_t *new_op(char const *op, int lvl, int length, OPERAND)
{
    operator_t *new_operator = malloc(sizeof(operator_t));

    new_operator->op = op;
    new_operator->level = lvl;
    new_operator->func = func;
    new_operator->length = length;
    return (new_operator);
}

operator_t **init_oplist(char *ops)
{
    operator_t **operators = malloc(sizeof(operator_t *) * 6);
    operators[0] = new_op(ops + OP_PLUS_IDX, 0, 1, &add);
    operators[1] = new_op(ops + OP_SUB_IDX, 0, 1, &sub);
    operators[2] = new_op(ops + OP_MULT_IDX, 1, 1, &mul);
    operators[3] = new_op(ops + OP_DIV_IDX, 1, 1, &divinf);
    operators[4] = new_op(ops + OP_MOD_IDX, 1, 1, &modinf);
    operators[5] = 0;
    return (operators);
}
