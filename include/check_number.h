/*
** EPITECH PROJECT, 2018
** check_number.h
** File description:
** number_t gestion header
*/

#ifndef CHECK_NUMBER_H
#define CHECK_NUMBER_H

int equalZero(number_t *, base_t *);
int equalOne(number_t *, base_t *);
int struct_cmp(number_t *, number_t *, base_t *);
number_t *create_zero(base_t *);
number_t *copy_number(number_t *base);

#endif // CHECK_NUMBER_H
