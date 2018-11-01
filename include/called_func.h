/*
** EPITECH PROJECT, 2018
** called_func
** File description:
** function called to make some computations
*/

#ifndef CALLED_CALC_H
#define CALLED_CALC_H
#include "number_manager.h"

number_t *called_min(number_t *, number_t *, int, base_t *);
number_t *called_max(number_t *, number_t *, int, base_t *);
number_t *called_add(number_t *, number_t *, base_t *);
number_t *called_sub(number_t *, number_t *, base_t *);
number_t *mulNums(number_t *, number_t *, base_t *);
void mul_add(number_t *, number_t *, base_t *, int);

#endif /* CALLED_CALC_H */
