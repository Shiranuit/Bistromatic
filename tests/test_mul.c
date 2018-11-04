/*
** EPITECH PROJECT, 2018
** mul_test.c
** File description:
** mul_test.c
*/

#include "all.h"
#include "test_func.h"
#include "unittest.h"

void test_mulnums(void)
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
        a->neg = 1;
        result = mul_nums(a, b, base);
        ut_assert_str_eq(result->str, "00400");
        ut_assert(result->neg == 0);
        free_number2(a, b);
        free_number(result);
    }
    free(base);
    free(all);
    ut_assert(exitcode == -1);
}

void test_mulnums_big(void)
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
        result = mul_nums(a, b, base);
        ut_assert_str_eq(result->str,
        "021907459734918796096205008185061682644871344719619634359980843852");
        ut_assert(result->neg == 0);
        free_number2(a, b);
        free_number(result);
    }
    free(base);
    free(all);
    ut_assert(exitcode == -1);
}

void test_mul_add(void)
{
    char *sa = "20";
    char *sb = "20";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);

    if (exitcode == -1) {
        mul_add(a, b, base, 0);
        ut_assert_str_eq(a->str, "00");
        ut_assert(a->neg == 0);
        free_number2(a, b);
    }
    free(base);
    free(all);
    ut_assert(exitcode == -1);
}

void test_mul(void)
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
        result = mul(a, b, base, all);
        ut_assert_str_eq(result->str, "400");
        ut_assert(result->neg == 0);
        free_number(result);
    }
    free(base);
    free(all);
    ut_assert(exitcode == -1);
}
