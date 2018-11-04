/*
** EPITECH PROJECT, 2018
** add_sub_test.c
** File description:
** add_sub_test.c
*/

#include <criterion/criterion.h>
#include "all.h"

void test_add(base_t *base, all_t *all)
{
    char *sa = "5";
    char *sb = "9";
    
    number_t *a = string_to_number(&sa, base);
    number_t *b = string_to_number(&sb, base);
    number_t *result = add(a, b, base, all);
    ut_assert_str_eq(result->str, "14"); 
}

void test_sub(base_t *base, all_t *all)
{
    char *sa = "55";
    char *sb = "80";
    
    number_t *a = string_to_number(&sa, base);
    number_t *b = string_to_number(&sb, base);
    number_t *result = add(a, b, base, all);
    ut_assert_str_eq(result->str, "25"); 
}

int main(void)
{
    base_t *base = malloc(sizeof(base_t));
    char *base_v = "()+-*/%";
    all_t *all = NULL;

    base->len = my_strlen(base_v) - 1;
    base->base = base_v;
    register_funct();
}