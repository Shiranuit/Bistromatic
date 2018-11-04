/*
** EPITECH PROJECT, 2018
** all.h
** File description:
** include all header
*/

#ifndef ALL_H
#define ALL_H

#include "base.h"

typedef struct all_s {
    base_t *base;
    char const *ops;
    int paranthesis;
    char *origin;
    int *exit;
} all_t;

#include "number_manager.h"
#include "called_func.h"
#include "operator.h"
#include "convert_base.h"
#include "bistromatic.h"
#include "buffer.h"
#include "exception.h"
#include "my.h"
#include "parser.h"
#include "utils.h"
#include "check_number.h"
#include "karatsuba.h"

#endif /* ALL_H */
