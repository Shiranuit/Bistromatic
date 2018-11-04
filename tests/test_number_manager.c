/*
** EPITECH PROJECT, 2018
** number_manager_test.c
** File description:
** number_manager_test.c
*/

#include "all.h"
#include "test_func.h"
#include "unittest.h"

void test_create_number(void)
{
    char *str = "test";
    number_t *result = create_number(str, 5, 0, 1);

    ut_assert(result->len == 5);
    ut_assert(result->neg == 0);
    ut_assert(result->free == 1);
    ut_assert_str_eq(result->str, "test");
    free_number(result);
}

void test_clear_zero(void)
{
    char *sa = "00006890";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);

    if (exitcode == -1) {
        clear_zero(a, base);
        ut_assert_str_eq(a->str, "6890");
        free_number(a);
    }
    ut_assert(exitcode == -1);
}

void test_free_number(void)
{
    char *sa = "20";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);

    if (exitcode == -1) {
        free_number(a);
        ut_assert(!a);
    }
    ut_assert(exitcode == -1);
}

void test_string_to_number(void)
{
    char *sa = "45789876434567655046298933440791355308923";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);

    if (exitcode == -1) {
        ut_assert_str_eq(a->str, "45789876434567655046298933440791355308923");
        free_number(a);
    }
    ut_assert(exitcode == -1);
}

void test_get_num(void)
{
    char *sa = "23";
    int exitcode = -1;
    base_t *base = init_base("0123456789");
    all_t *all = init_all("", base, &exitcode);
    number_t *a = string_to_number(&sa, base, all);

    if (exitcode == -1) {
        ut_assert(get_num(a, 0, base) == 3);
        free_number(a);
    }
    ut_assert(exitcode == -1);
}
