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
    exec_test();
}
