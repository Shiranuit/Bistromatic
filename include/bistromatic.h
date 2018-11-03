/*
** EPITECH PROJECT, 2018
** Bistromatic.h
** File description:
** Bistromatic exeptions header
*/

#ifndef BISTROMATIC_H
#define BISTROMATIC_H

#include "number_manager.h"

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84
#define EXIT_INVALID_EXP 84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"
#define ERROR_INVALID_EXPR "invalid expr"

number_t *eval_expr(char *, char *, char *, base_t *);

#endif /* BISTROMATIC_H */
