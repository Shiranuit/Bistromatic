/*
** EPITECH PROJECT, 2018
** operand
** File description:
** operand
*/

#include "all.h"
#include <stdlib.h>

number_t *unm(number_t *right, all_t *all)
{
    if (*(all->exit) == -1) {
        right->neg = !right->neg;
        return (right);
    }
    return (0);
}
