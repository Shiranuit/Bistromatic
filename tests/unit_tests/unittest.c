/*
** EPITECH PROJECT, 2018
** unittest
** File description:
** unittest
*/

#include <signal.h>
#include <stdlib.h>
#include "unittest.h"
#include "ut_utils.h"

test_t *list;
test_t *running;
int success;
int fail;
int crash;

void register_test(char *name, char *desc, void (*func)(void))
{
    test_t *new_test = malloc(sizeof(test_t));

    new_test->name = name;
    new_test->desc = desc;
    new_test->func = func;
    new_test->next = list;
    list = new_test;
}

void end_test(int count, int success, int fail, int crash)
{
    mwrite("[\x1B[34m====\x1B[0m] Synthesis: Tested: \x1B[34m");
    mwrite_int(count);
    mwrite("\x1B[0m | Passing: \x1B[32m");
    if (success <= 0)
        mwrite("\x1B[0m");
    mwrite_int(success);
    mwrite("\x1B[0m | Failing: \x1B[31m");
    if (fail <= 0)
        mwrite("\x1B[0m");
    mwrite_int(fail);
    mwrite("\x1B[0m | Crashing: \x1B[31m");
    if (crash <= 0)
        mwrite("\x1B[0m");
    mwrite_int(crash);
    mwrite("\n");
}

void exec_test(void)
{
    int count = 0;
    running = list;

    while (running) {
        count++;
        signal(SIGSEGV, segfault);
        running->func();

        running = running->next;
    }
    end_test(count, success, fail, crash);
}
