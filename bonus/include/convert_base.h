/*
** EPITECH PROJECT, 2018
** convert_base.h
** File description:
** base gestion header
*/

#ifndef CONVERT_BASE_H
#define CONVERT_BASE_H
#include "all.h"

int base_to_int(char, base_t *);
char int_to_base(int, base_t *);
void check_params(base_t *, char *, all_t *);

#endif /* CONVERT_BASE_H */