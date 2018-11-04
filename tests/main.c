/*
** EPITECH PROJECT, 2018
** main.cs
** File description:
** main.c
*/

#include "test_func.h"
#include "unittest.h"

int main(void)
{
    register_test("add", "basic_add", &test_add);
    register_test("called_add", "basic_add", &test_called_add);
    register_test("add", "big_add", &test_add);
    register_test("called_add", "big_called_add", &test_called_add);
    register_test("clear_zero", "check_clear_zero", &test_called_add);
    register_test("free_number", "check_free_number", &test_called_add);
    register_test("create_number", "check_create_number", &test_called_add);
    register_test("get_num", "check_get_num", &test_called_add);
    register_test("string_to_number", "check_string_to_num", &test_called_add);
    exec_test();
}
