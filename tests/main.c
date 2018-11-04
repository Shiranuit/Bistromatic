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
    register_test("sub", "basic_sub", &test_sub);
    register_test("sub", "sub_neg", &test_sub2);
    register_test("readc", "check_readc", &test_readc);
    register_test("move", "check_move", &test_move);
    register_test("skip_whitespace", "check_whitesp", &test_skip_whitespace);
    register_test("int_to_base", "check_int_to_base", &test_int_to_base);
    register_test("base_to_int", "check_base_to_int", &test_base_to_int);
    register_test("mul", "multiplication", &test_mul);
    register_test("mulnums", "basic_mul", &test_mulnums);
    register_test("mulnums", "big_mul", &test_mulnums_big);
    register_test("mul_add", "check_base_to_int", &test_mul_add);
    register_test("karatsuba", "karatsuba_mul", &test_karatsuba_mul);
    register_test("eval_expr", "add_basic", &test_eval_expr1);
    register_test("eval_expr", "sub_basic", &test_eval_expr2);
    exec_test();
}
