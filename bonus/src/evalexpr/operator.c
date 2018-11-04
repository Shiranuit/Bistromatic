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
    operator_t **operators = malloc(sizeof(operator_t *) * 13);
    
    operators[0] = new_op("&&", 0, 2, &and);
    operators[1] = new_op("||", 0, 2, &or);
    operators[2] = new_op(">=", 1, 2, &greater_or_equal);
    operators[3] = new_op("<=", 1, 2, &less_or_equal);
    operators[4] = new_op(">", 1, 1, &greater_than);
    operators[5] = new_op("<", 1, 1, &less_than);
    operators[6] = new_op("==", 1, 2, &equal);
    operators[7] = new_op(ops + OP_PLUS_IDX, 2, 1, &add);
    operators[8] = new_op(ops + OP_SUB_IDX, 2, 1, &sub);
    operators[9] = new_op(ops + OP_MULT_IDX, 3, 1, &mul);
    operators[10] = new_op(ops + OP_DIV_IDX, 3, 1, &divinf);
    operators[11] = new_op(ops + OP_MOD_IDX, 3, 1, &modinf);
    operators[12] = 0;
    return (operators);
}
