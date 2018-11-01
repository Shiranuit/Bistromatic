/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** div.c
*/

#include "all.h"

void calc_div(number_t *a, int b, int size, char *result)
{

}

number_t *do_div(number_t *a, number_t *b, base_t *base)
{
    int size = a->len + 1
    char *res = malloc(sizeof(char) * size)
    number_t *min = called_min(a, b, 0, base);
    number_t *max = called_max(a, b, 0, base);
    number_t *result = create_number(res, size, 0, 2);
    print_number(min);
    print_number(max);

    calc_div(max, b, size, 0);
    result->neg = a->neg^b->neg;
    return (result);
}

number_t *diiv(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result;

    (void)all;
    clear_zero(a, base);
    clear_zero(b, base);
    result = do_div(a, b, base);
    free_number(a);
    free_number(b);
    return (clear_zero(result, base));
}
