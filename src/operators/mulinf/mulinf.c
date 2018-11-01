#include "all.h"

void called_mul(number_t *a, int b, base_t *base, char *new_str)
{
    int len = a->len + 1;
    int sum = 0;
    int carry = 0;

    for (int i = 0; i < len - 1; i++) {
        sum = get_num(a, i, base) * b + carry;
        new_str[len - i - 2] = int_to_base(sum % base->len, base);
        carry = sum / base->len;
    }
    new_str[len - 1] = '\0';
}

void mul_add(number_t *a, number_t *b, base_t *base, int mv)
{
    int len = a->len;
    long long sum = 0;
    long long carry = 0;

    for (int i = 0; i < len - 1; i++) {
        sum = carry;
            sum += get_num(a, i, base) > -1 ? get_num(a, i, base) : 0;
            sum += get_num(b, i - mv, base);
        carry = sum / base->len;
        if (sum > base->len - 1)
            sum = sum % base->len;
        a->str[len - i - 2] = int_to_base(sum, base);
    }
    a->str[0] = int_to_base(carry, base);
}

number_t *mulNums(number_t *a, number_t *b, base_t *base)
{
    number_t *min = called_min(a, b, 0, base);
    number_t *max = called_max(a, b, 0, base);
    int size = a->len + b->len;
    char *add_str = create_char(size, base);
    char *data = create_char(max->len + 1, base);
    number_t *n_data = create_number(data, max->len + 1, 0, 2);
    number_t *result = create_number(add_str, size, 0, 2);

    for (int i = 0; i < min->len - 1; i++) {
        called_mul(max, get_num(min, i, base), base, data);
        mul_add(result, n_data, base, i);
    }
    free_number(n_data);
    result->neg = a->neg ^ b->neg;
    return (result);
}

number_t *recmul(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result;

    if (equalZero(a, base) || equalZero(b, base) || !a || !b)
        return (create_zero(base));
    if (equalOne(a, base) || equalOne(b, base))
        return (equalOne(a, base) ? b : a);
    if (a->len - 1 < 80 && b->len - 1 < 80)
        result = mulNums(a, b, base);
    else
        result = karatsuba_mul(a, b, base, all);
    return (result);
}

number_t *mul(number_t *a, number_t *b, base_t *base, all_t *all)
{
    number_t *result = recmul(a, b, base, all);

    free_number(a);
    free_number(b);
    return (clear_zero(result, base));
}
