/*
** EPITECH PROJECT, 2018
** unittest_header
** File description:
** unittest_header
*/

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "compare.h"

typedef struct test_s {
    char *name;
    char *desc;
    void (*func)(void);
    struct test_s *next;
} test_t;

void segfault(int);
void execTest(void);
void registerTest(char *, char *, void (*)(void));
void endTest(int, int, int, int);

extern test_t *list;
extern test_t *running;
extern int success;
extern int fail;
extern int crash;

#endif // STRUCT_TEST_H
