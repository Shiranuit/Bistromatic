/*
** EPITECH PROJECT, 2018
** number_header
** File description:
** number_header
*/

#ifndef NUMBER_MANAGER_H
#define NUMBER_MANAGER_H

typedef struct number_s
{
    char *str;
    char *origin;
    int len;
    int free;
    int neg;
} number_t;

typedef struct base_s
{
    char const *base;
    int len;
} base_t;

number_t *create_number(char *, int, int, int);
number_t *clear_zero(number_t *, base_t *);
number_t *string_to_number(char **, base_t *);
void *free_number(number_t *);
int get_num(number_t *, int, base_t *);

#endif /* NUMBER_MANAGER_H */
