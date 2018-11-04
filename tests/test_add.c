/*
** EPITECH PROJECT, 2018
** add_test.c
** File description:
** add_test.c
*/

#include "all.h"
#include "test_func.h"
#include "unittest.h"

void test_add(void)
{
    char *sa = "20";
    char *sb = "20";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    number_t *result;

    if (exitcode == -1) {
        result = add(a, b, base, all);
        ut_assert_str_eq(result->str, "40");
        free_number(result);
    }
    ut_assert(exitcode == -1);
}

void test_add_big(void)
{
    char *sa = "45789876434567654567864365786434567654356";
    char *sb = "478434567654356787654567";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    number_t *result;

    if (exitcode == -1) {
        result = add(a, b, base, all);
        ut_assert_str_eq(result->str, "45789876434567655046298933440791355308923");
        free_number(result);
    }
    ut_assert(exitcode == -1);
}

void test_called_add(void)
{
    char *sa = "20";
    char *sb = "20";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    number_t *result;

    if (exitcode == -1) {
        result = called_add(a, b, base);
        ut_assert_str_eq(result->str, "040");
        free_number2(a, b);
        free_number(result);
    }
    ut_assert(exitcode == -1);
}

void test_called_add_big(void)
{
    char *sa = "45789876434567655046298933440791355308923";
    char *sb = "478434567654356787654567";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    number_t *result;

    if (exitcode == -1) {
        result = called_add(a, b, base);
        ut_assert_str_eq(result->str, "45789876434567655046298933440791355308923");
        free_number2(a, b);
        free_number(result);
    }
    ut_assert(exitcode == -1);
}
