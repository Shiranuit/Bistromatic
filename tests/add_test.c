/*
** EPITECH PROJECT, 2018
** add_sub_test.c
** File description:
** add_sub_test.c
*/

#include "all.h"
#include "unittest.h"

void test_add(base_t *base, all_t *all)
{
    base_t *base = malloc(sizeof(base_t));
    char *base_v = "()+-*/%";
    all_t *all = NULL;
    char *sa = "5";
    char *sb = "9";
    number_t *a;
    number_t *b;
    number_t *result;
    
    a = string_to_number(&sa, base);
    b = string_to_number(&sb, base);
    result = add(a, b, base, all);
    ut_assert_str_eq(result->str, "14"); 
}

void test_sub(base_t *base, all_t *all)
{
    base_t *base = malloc(sizeof(base_t));
    char *base_v = "()+-*/%";
    all_t *all = NULL;
    char *sa = "55";
    char *sb = "80";
    number_t *a;
    number_t *b;
    number_t *result;

    base->len = my_strlen(base_v) - 1;
    base->base = base_v;
    a = string_to_number(&sa, base);
    b = string_to_number(&sb, base);
    result = add(a, b, base, all);
    ut_assert_str_eq(result->str, "25");
}

int main(void)
{
    register_test("add", "basic_add", &add);
    register_test("sub", "basic_sub", &sub);
}