/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils
*/

#ifndef UTILS_H
#define UTILS_H
#include "number_manager.h"

void print_number(number_t *, base_t *);
void *free_number2(number_t *, number_t *);
char *create_char(int, base_t *);
int struct_ncmp(number_t *a, number_t *b, base_t *base, int mv);

#endif /* UTILS_H */
