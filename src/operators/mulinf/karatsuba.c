/*
** EPITECH PROJECT, 2018
** Karatsuba
** File description:
** fast multiplication
*/

#include "all.h"

number_t *getLower(number_t *a, int n)
{
    if (a->len - 1 <= n)
        return (create_number(a->str, a->len, 0, 1));
    return (create_number(a->str + a->len - n - 1, n + 1, 0, 1));
}

number_t *getUpper(number_t *a, int n)
{
    if (a->len - 1 <= n)
        return (create_number(a->str, 0, 0, 1));
    return (create_number(a->str, a->len - n, 0, 1));
}

void free_karatsuba(karatsuba_t *kara)
{
    free_number(kara->aHigh);
    free_number(kara->aLow);
    free_number(kara->bHigh);
    free_number(kara->bLow);
    free_number(kara->abHigh);
    free_number(kara->abLow);
    free_number(kara->aHL);
    free_number(kara->bHL);
    free_number(kara->res);
    free(kara);
}

void setup_uplow(number_t *a, number_t *b, karatsuba_t *kara, int half)
{
    kara->aHigh = getUpper(a, half);
    kara->aLow = getLower(a, half);
    kara->bHigh = getUpper(b, half);
    kara->bLow = getLower(b, half);
}

number_t *karatsuba_mul(number_t *a, number_t *b, base_t *base, all_t *all)
{
    karatsuba_t *kara = malloc(sizeof(karatsuba_t));
    int size = a->len + b->len + 1;
    int h = (a->len > b->len ? a->len : b->len) / 2;
    char *data = create_char(size, base);
    number_t *result = create_number(data, size, 0, 2);

    setup_uplow(a, b, kara, h);
    kara->abHigh = recmul(kara->aHigh, kara->bHigh, base, all);
    kara->abLow = recmul(kara->aLow, kara->bLow, base, all);
    kara->aHL = called_add(kara->aHigh, kara->aLow, base);
    kara->bHL = called_add(kara->bHigh, kara->bLow, base);
    kara->res = recmul(kara->aHL, kara->bHL, base, all);
    div_sub(kara->res, kara->abHigh, base, 0);
    div_sub(kara->res, kara->abLow, base, 0);
    mul_add(result, kara->abHigh, base, 2 * h);
    mul_add(result, kara->res, base, h);
    mul_add(result, kara->abLow, base, 0);
    free_karatsuba(kara);
    return (result);
}
