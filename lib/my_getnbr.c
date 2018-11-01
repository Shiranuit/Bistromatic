/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** lib
*/

#include "all.h"

int my_getnbr(char const *str)
{
    long result = 0;
    int i = 0;
    int signe = 1;

    for (i = 0; str[i] != '\0' && (str[i] == '-' || str[i] == '+'); i++) {
        if (str[i] == '-')
            signe = -1;
    }
    for (;str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            result = (result * 10) + str[i] - 48;
        if (signe == -1 && result > 2147483648)
            return (0);
        if (signe == 1 && result > 2147483647)
            return (0);
    }
    return ((int)result * signe);
}
