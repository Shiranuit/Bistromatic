/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

#include <stdio.h>
#include "all.h"
#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

void print_number(number_t *a)
{
    if (a->neg == 1 && a->len > 1 && a->str[0] != '0')
        write(1, "-", 1);
    write(1, a->str, a->len);
}
