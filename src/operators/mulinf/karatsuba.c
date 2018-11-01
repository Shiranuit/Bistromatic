/*
** EPITECH PROJECT, 2018
** Karatsuba
** File description:
** fast multiplication
*/

#include "all.h"

number_t *getLower(number_t *a, int n, base_t *base)
{
    char *new_str = create_char(n + 1, base);
    int j = 0;

    for (int i = a->len - n - 1; i < a->len; i++, j++)
        if (i > -1 && i < a->len - 1)
            new_str[j] = a->str[i];
    return (create_number(new_str, n + 1, 0, 2));
}

number_t *getUpper(number_t *a, int n, base_t *base)
{
    char *new_str;
    int j = 0;
    int sz = a->len - n * 2;

    if (a->len - 1 <= n)
        return (create_zero(base));
    new_str = create_char(n + 1, base);
    for (int i = sz - 1; i < a->len - n - 1; i++, j++)
        if (i > -1 && i < a->len - 1)
            new_str[j] = a->str[i];
    return (create_number(new_str, n + 1, 0, 2));
}

void free_4(number_t *a, number_t *b, number_t *c, number_t *d)
{
    free_number(a);
    free_number(b);
    free_number(c);
    if (d != 0)
        free_number(d);
}

number_t *couple(base_t *base, all_t *all, mult_data_t *info)
{
    number_t *result;
    number_t *x;
    number_t *y;

    if (info->up == 1) {
        x = getUpper(info->a, info->half, base);
        y = getUpper(info->b, info->half, base);
        result = recmul(x, y, base, all);
    } else {
        x = getLower(info->a, info->half, base);
        y = getLower(info->b, info->half, base);
        result = recmul(x, y, base, all);
    }
    free_number(x);
    free_number(y);
    free(info);
    return (result);
}

mult_data_t *create_mdata(number_t *a, number_t *b, int up, int half)
{
    mult_data_t *data = malloc(sizeof(mult_data_t));

    data->up = up;
    data->half = half;
    data->a = a;
    data->b = b;
    return (data);
}

number_t *karatsuba_mul(number_t *a, number_t *b, base_t *base, all_t *all)
{
    int size = a->len + b->len + 1;
    int h = (a->len > b->len ? a->len : b->len) / 2;
    char *data = create_char(size, base);
    number_t *result = create_number(data, size, 0, 2);
    number_t *x = couple(base, all, create_mdata(a, b, 1, h));
    number_t *y = couple(base, all, create_mdata(a, b, 0, h));
    number_t *cx = add(getUpper(a, h, base), getLower(a, h, base), base, all);
    number_t *cy = add(getUpper(b, h, base), getLower(b, h, base), base, all);
    number_t *e = recmul(cx, cy, base, all);
    number_t *z = called_sub(e, x, base);
    number_t *r = called_sub(z, y, base);

    mul_add(result, x, base, 2 * h);
    mul_add(result, r, base, h);
    mul_add(result, y, base, 0);
    free_4(x, y, cx, cy);
    free_4(e, z, r, 0);
    return(result);
}
