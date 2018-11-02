/*
** EPITECH PROJECT, 2018
** operator
** File description:
** operator
*/

#ifndef OPERATOR_H
#define OPERATOR_H
#include "number_manager.h"

static int const OPLVMAX = 1;
#define OPERAND number_t *(*func)(number_t *, number_t *, base_t *, all_t *)

typedef struct operator {
    char const *op;
    int level;
    int length;
    number_t *(*func)(number_t *, number_t *, base_t *, all_t *);
} operator_t;

operator_t *new_op(char const *, int, int, OPERAND);
operator_t **init_oplist();
number_t *add(number_t *, number_t *, base_t *, all_t *);
number_t *sub(number_t *, number_t *, base_t *, all_t *);
number_t *mul(number_t *, number_t *, base_t *, all_t *);
number_t *karatsuba_mul(number_t *, number_t *, base_t *, all_t *);
// number_t *diiv(number_t *, number_t *, base_t *, all_t *);
number_t *unm(number_t *, all_t *);

#endif /* OPERATOR_H */
