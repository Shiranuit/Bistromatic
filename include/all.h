/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** all.h
*/

#ifndef ALL_H
#define ALL_H
#include "number_manager.h"

typedef struct all_s {
    base_t *base;
    char const *ops;
    int paranthesis;
    char *origin;
    int *exit;
} all_t;

#include "operator.h"
#include "convert_base.h"
#include "bistromatic.h"
#include "buffer.h"
#include "called_func.h"
#include "exception.h"
#include "my.h"
#include "parser.h"
#include "utils.h"
number_t *called_mx(number_t *, number_t *, base_t *);
number_t *called_mn(number_t *, number_t *, base_t *);

#endif /* ALL_H */
