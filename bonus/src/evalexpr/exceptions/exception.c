/*
** EPITECH PROJECT, 2018
** exception
** File description:
** exception
*/

#include "all.h"
#include <stdlib.h>
#include <unistd.h>

void *exception(char const *err, all_t *all)
{
    int len = 0;

    if (*(all->exit) == -1) {
        while (err[len++]);
        write(2, err, len);
        *(all->exit) = 84;
    }
    return (0);
}
