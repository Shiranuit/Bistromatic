/*
** EPITECH PROJECT, 2018
** all.h
** File description:
** include all header
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
#include "check_number.h"
#include "mult_data.h"

#endif /* ALL_H */
