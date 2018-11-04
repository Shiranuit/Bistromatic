/*
** EPITECH PROJECT, 2018
** exception
** File description:
** exception
*/

#include <stdio.h>
#include "unittest.h"
#include "ut_utils.h"

void segfault(int seg)
{
    (void)seg;
    mwrite("Segfault in '");
    mwrite(running->name);
    mwrite("' function\n");
    crash++;
}
