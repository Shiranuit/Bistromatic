/*
** EPITECH PROJECT, 2018
** add_sub_test.c
** File description:
** add_sub_test.c
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
    all_t *all = init_all("20+20", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);
    number_t *b = string_to_number(&sb, base, all);
    if (exitcode == -1) {
        number_t *result = add(a, b, base, all);

        ut_assert_str_eq(result->str, "40");
    }
    ut_assert(exitcode == -1);
}
