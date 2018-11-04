#ifndef TEST_FUNC_H
#define TEST_FUNC_H
#include "all.h"

base_t *init_base(char *base_v);
all_t *init_all(char *expr, base_t *base, int *exitcode);

void test_add(void);
void test_called_add(void);
void test_add_big(void);
void test_called_add_big(void);
void test_get_num(void);
void test_string_to_number(void);
void test_free_number(void);
void test_clear_zero(void);
void test_create_number(void);

#endif // TEST_FUNC_H
