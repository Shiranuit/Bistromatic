#ifndef TEST_FUNC_H
#define TEST_FUNC_H

base_t *init_base(char *base_v);
all_t *init_all(char *expr, base_t *base, int *exitcode);

void test_add(void);

#endif // TEST_FUNC_H
