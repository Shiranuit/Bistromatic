/*
** EPITECH PROJECT, 2018
** karatsuba_test.c
** File description:
** karatsuba_test.c
*/

#include "all.h"
#include "unittest.h"
#include "test_func.h"

void test_karatsuba_mul(void)
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
        result = karatsuba_mul(a, b, base, all);
        ut_assert_str_eq(result->str, "000400");
        free_number2(a, b);
        free_number(result);
    }
    free(base);
    free(all);
    ut_assert(exitcode == -1);
}
