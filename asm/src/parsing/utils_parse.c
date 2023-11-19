/*
** EPITECH PROJECT, 2023
** utils parsing fonctions
** File description:
** utils_parse
*/

/* system INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "op.h"
#include "utils.h"
#include "print.h"
#include "asm.h"

char **remove_comments(char **parsed_file_lines)
{
    for (int i = 0; parsed_file_lines[i] != NULL; i++) {
        parsed_file_lines[i] = is_comment(parsed_file_lines[i]);
    }
    return parsed_file_lines;
}

char *my_full_fill_strncpy(char *dest, const char *src, int n)
{
    int i, j;
    my_memset(dest, '\0', n);
    for (i = 0, j = 0; src[i] && j < n; i++) {
        if (src[i] != '"') {
            dest[j] = src[i];
            j++;
        }
    }
    return dest;
}

int find_len_optab(char *const mnemonic)
{
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(mnemonic, op_tab[i].mnemonique) == 0) {
            return op_tab[i].nbr_args;
        }
    }
    return 0;
}

int get_value(char *value_str)
{
    int value = 0, j = 0;
    char *temp_str = malloc(sizeof(char) * my_strlen(value_str));
    my_memset(temp_str, '\0', my_strlen(value_str));
    if (value_str[0] == 'r' || value_str[0] == '%') {
        for (int i = 1; value_str[i] != '\0'; i++) {
            temp_str[j] = value_str[i];
            j++;
        }
        value = my_get_nbr(temp_str);
        return value;
    } else {
        value = my_get_nbr(value_str);
    }
    return value;
}
