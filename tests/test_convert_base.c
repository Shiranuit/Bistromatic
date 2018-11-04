/*
** EPITECH PROJECT, 2018
** buffer_test.c
** File description:
** buffer_test.c
*/

#include "all.h"
#include "unittest.h"
#include "test_func.h"

void test_int_to_base(void)
{

    int exitcode = -1;
    base_t *base = init_base("A123456789");
    all_t *all = init_all("", base, &exitcode);

    ut_assert(int_to_base(0, base) == 'A');
    free(base);
    free(all);
}

void test_base_to_int(void)
{

    int exitcode = -1;
    base_t *base = init_base("A123456789");
    all_t *all = init_all("", base, &exitcode);

    ut_assert(base_to_int('3', base) == 3);
    free(base);
    free(all);
}
