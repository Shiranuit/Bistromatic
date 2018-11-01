/*
** EPITECH PROJECT, 2018
** buffer
** File description:
** buffer
*/

#include "all.h"

char readc(char **str)
{
    move(str, 1);
    return ((*str)[-1]);
}

void move(char **str, int step)
{
    *str = *str + step;
}

void skip_space(char **str)
{
    while (readc(str) == ' ');
    move(str, -1);
}
