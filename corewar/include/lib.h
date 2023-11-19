/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** include lib
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef LIB_H_
    #define LIB_H_

    #define SUCCESS 0
    #define ERROR -1
    #define EPITECH_ERROR 84

    //TOOLS
    int my_putchar(char c);
    int my_putstr(char const *str);
    int my_put_error(char const *str);
    int my_put_nbr(int nb);
    int my_strlen(char const *str);
    int get_nbr(char *charact);

    //ARRAY
    void free_arr(char **arr);
    void print_arr(char **arr);
    int get_longest_string_length(char **tab);

    //STR
    int count_words(char *str, char *const separator);
    char *my_strcat(char *dest, char const *src);
    char *my_strdup(const char *s);
    int my_strcmp(const char *s1, const char *s2);
    int my_strncmp(const char *s1, const char *s2, size_t n);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    bool my_str_isalpha(char const *str);

#endif
