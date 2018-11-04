/*
** EPITECH PROJECT, 2018
** buffer_test.c
** File description:
** buffer_test.c
*/

#include "all.h"
#include "unittest.h"
#include "test_func.h"

void test_readc(void)
{
    char *str = "test";

    readc(&str);
    ut_assert_str_eq(str, "est");
}

void test_move(void)
{
    char *str = "test";

    move(&str, 2);
    ut_assert_str_eq(str, "st");
}

void test_skip_whitespace(void)
{
    char *str = "        test";

    skip_space(&str);
    ut_assert_str_eq(str, "test");
}
