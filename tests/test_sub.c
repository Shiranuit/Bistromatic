/*
** EPITECH PROJECT, 2018
** test_sub
** File description:
** test_sub
*/

#include "all.h"
#include "unittest.h"
#include "test_func.h"

void test_sub(void)
{
    number_t *result;
    char *sa = "20";
    char *sb = "20";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    if (exitcode == -1) {
        result = sub(a, b, base, all);
        ut_assert_str_eq(result->str, "0");
        free_number(result);
    }
    ut_assert(exitcode == -1);
    free(base);
    free(all);
}

void test_sub2(void)
{
    number_t *result;
    char *sa = "2A";
    char *sb = "20";
    int exitcode = -1;
    base_t *base = init_base("0123456789ABCDEF");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    if (exitcode == -1) {
        b->neg = 1;
        result = sub(a, b, base, all);
        ut_assert_str_eq(result->str, "4A");
        free_number(result);
    }
    ut_assert(exitcode == -1);
    free(base);
    free(all);
}