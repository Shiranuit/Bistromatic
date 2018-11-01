/*
** EPITECH PROJECT, 2018
** operand
** File description:
** operand
*/

#include "all.h"
#include <stdlib.h>

number_t *unm(number_t *right)
{
    right->neg = !right->neg;
    return (right);
}
