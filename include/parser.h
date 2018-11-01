/*
** EPITECH PROJECT, 2018
** parser_header
** File description:
** parser_header
*/

#ifndef PARSER_H
#define PARSER_H
#include "all.h"

number_t *parse_expression(char **, int level, operator_t **, all_t *);
number_t *parse_unm(char **, operator_t **, all_t *);
number_t *parse_val(char **, operator_t **, all_t *);
number_t *parse(char **, all_t *);
operator_t *readoplevel(char **, int, operator_t **, all_t *);

#endif /* PARSER_H */
