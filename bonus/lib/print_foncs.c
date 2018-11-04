/*
** EPITECH PROJECT, 2018
** CPool_bistro-matic_2018
** File description:
** print_foncs
*/

#include "all.h"

int my_putchar(char c)
{
    if (!c)
        return (84);
    write (1, &c, 1);
    return (0);
}

void my_putstr(char const *str)
{
    if (!str)
        return;
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int put_error(char *str)
{
    if (!str)
        return (84);
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i + 1);
}
