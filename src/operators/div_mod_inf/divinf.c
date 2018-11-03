/*
** EPITECH PROJECT, 2018
** difinf
** File description:
** infinite division
*/

#include "all.h"

int struct_ncmp(number_t *a, number_t *b, base_t *base, int mv)
{
    clear_zero(a, base);
    clear_zero(b, base);
    if (a->len > b->len + mv)
        return (1);
    if (a->len < b->len + mv)
        return (-1);
    for (int i = a->len - 1; i >= 0; i--) {
        if (get_num(a, i, base) > get_num(b, i - mv, base))
            return (1);
        if (get_num(a, i, base) < get_num(b, i - mv, base))
            return (-1);
    }
    return (0);
}

number_t *do_div(number_t *a, number_t *b, base_t *base)
{
    int mv = a->len - b->len - 1;
    char *new_str = create_char(a->len + 1, base);
    char *count = create_char(3, base);
    number_t *result = create_number(new_str, a->len + 1, 0, 2);
    number_t *cnt = create_number(count, 3, 0, 2);
    int res = 0;

    mv = struct_ncmp(a, b, base, mv + 1) == 1 ? mv + 1 : mv;
    count[2] = '\0';
    while (mv > -1) {
        if  (struct_ncmp(a, b, base, mv) == -1) {
            mv--;
            count[1] = int_to_base(res % base->len, base);
            count[0] = int_to_base(res / base->len, base);
            mul_add(result, cnt, base, mv + 1);
            res = 0;
        }
        if (mv > -1 && struct_ncmp(a, b, base, mv) >= 0) {
            div_sub(a, b, base, mv);
            res++;
        }
    }
    free_number(cnt);
    return (result);
}

number_t *divinf(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result;
    int cmp = struct_cmp(a, b, base);

    if (equal_zero(b, base))
        return (exception(ERROR_MSG, all));
    if (cmp == -1)
        return (create_zero(base));
    if (cmp == 0)
        return (create_one(base));
    result = clear_zero(do_div(a, b, base), base);
    result->neg = a->neg ^ b->neg;
    free_number2(a, b);
    return (result);
}
