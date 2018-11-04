/*
** EPITECH PROJECT, 2018
** mul_test.c
** File description:
** mul_test.c
*/

#include "all.h"
#include "test_func.h"
#include "unittest.h"
#include <stdlib.h>

void test_eval_expr1(void)
{
    char *b = strdup("0123456789");
    char *ops = strdup("()+-*/%");
    char *expr = strdup("20+21");
    base_t *base = init_base(b);
    number_t *result = eval_expr(b, ops, expr, base);

    ut_assert_str_eq(result->str, "41");
    ut_assert(result->neg == 0);
    free_number(result);
    free(base);
    free(ops);
    free(b);
}

void test_eval_expr2(void)
{
    char *b = strdup("0123456789");
    char *ops = strdup("()+-*/%");
    char *expr = strdup("20-21");
    base_t *base = init_base(b);
    number_t *result = eval_expr(b, ops, expr, base);

    ut_assert_str_eq(result->str, "1");
    ut_assert(result->neg == 1);
    free_number(result);
    free(base);
    free(ops);
    free(b);
}

void test_eval_expr4(void)
{
    char *b = strdup("0123456789");
    char *ops = strdup("()+-*/%");
    char *expr = strdup("-----6*12");
    base_t *base = init_base(b);
    number_t *result = eval_expr(b, ops, expr, base);

    ut_assert_str_eq(result->str, "72");
    ut_assert(result->neg == 1);
    free_number(result);
    free(base);
    free(ops);
    free(b);
}
