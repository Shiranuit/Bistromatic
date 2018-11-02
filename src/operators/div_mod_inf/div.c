/*
** EPITECH PROJECT, 2018
** div
** File description:
** div
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *mul(char *a, char *b);
char *sub(char *a, char *b);

char *remove_zeros(char *str) //clear zero;
{
    while (*str == '0' && *(str + 1) != 0)
        str += 1;
    return (str);
}

int	cmp_strs(char *nbr1, char *nbr2)
{
    int len1 = strlen(nbr1); //a->len
    int len2 = strlen(nbr2); //b->len

    if (len1 > len2)
        return (1);
    else if (len1 < len2)
        return (-1);
    else
        return (strcmp(nbr1, nbr2));
    return (0);
}

char *calc_div(char *a, char *b, char **tab)
{
    char *count = strdup("0");
    int val[3];
    char *tmp = mul(b, count);

    val[0] = strlen(a) + ((val[1] = strlen(b)) + (val[2] = -1)) * 0;
    tmp[strlen(tmp)] = 0;
    while (cmp_strs(tmp, a) < 0) {
        count[0] += 1;
        tmp = (count[0] == 58) ? mul(b, strdup("10")) : mul(b, count);
    }
    if (cmp_strs(tmp, a) != 0)
        count[0] -= 1;
    *tab = count;
    return ((cmp_strs(tmp, a) == 0) ? "0" : sub(a, sub(tmp, b)));
}

void concer(char *a, char *b, char *tmp1, char *res, int *val)
{
    char *q = malloc(sizeof(char) * 2);
    char *tmp = NULL;

    while (a[val[0] - 1] != 0) {
        tmp = calc_div(tmp1, b, &q);
        res[val[0] - val[2]] = q[0] + 0 * (val[3] = strlen(tmp));
        strcpy(tmp1, tmp);
        tmp1[val[3]] = a[val[0]];
        val[0] += 1;
        tmp1[val[3] + 1] = 0;
        tmp1 = remove_zeros(tmp1);
    }
    free(q);
}

char *infin_div_loop(char *a, char *b, int *val)
{
    char *tmp1 = malloc(sizeof(char) * (val[1] + 2));
    char *res = malloc(sizeof(char) * (val[1] + 2));
    char *q = malloc(sizeof(char) * 2);

    if (tmp1 == NULL || res == NULL || q == NULL)
        exit(84);
    memset(res, 0, val[1]);
    strcpy(tmp1, a);
    tmp1[val[0]] = 0;
    concer(a, b, tmp1, res, val);
    return (res);
}

char *div_inf(char *a, char *b)
{
    char *res;
    int val[4];

    if (b[0] == '1' && b[1] == 0)
        return (strdup(a));
    if (cmp_strs(a, b) < 0)
        return (strdup("0"));
    val[1] = strlen(a);
    val[2] = strlen(b);
    val[0] = val[2];
    res = infin_div_loop(a, b, val);
    res[val[0] - val[2]] = 0;
    return (res);
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    printf("%s\n", div_inf(av[1], av[2]));
    return (0);
}
