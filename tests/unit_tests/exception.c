/*
** EPITECH PROJECT, 2018
** exception
** File description:
** exception
*/

#include <stdio.h>
#include "unittest.h"
#include "ut_utils.h"

void segfault(int id)
{
    (void)id;
    mwrite("Segfault in '");
    mwrite(running->name);
    mwrite("' function\n");
    crash++;
}

void illeg_instruction(int id)
{
    (void)id;
    mwrite("Illegal Instruction in '");
    mwrite(running->name);
    mwrite("' function\n");
    crash++;
}

void buserror(int seg)
{
    (void)seg;
    mwrite("Bus Error in '");
    mwrite(running->name);
    mwrite("' function\n");
    crash++;
}

void arithmerror(int id)
{
    (void)id;
    mwrite("Arithmetic Error in '");
    mwrite(running->name);
    mwrite("' function\n");
    crash++;
}
