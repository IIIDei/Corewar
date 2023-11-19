/*
** EPITECH PROJECT, 2023
** all error_handling fonction
** File description:
** error_handling
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

bool good_param_type(char *mnemonic, char **params)
{
    op_t mnemonic_line;
    char *first_str = params[0];
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(mnemonic, op_tab[i].mnemonique) == 0) {
            mnemonic_line = op_tab[i];
        }
    }
    for (int i = 0; i < mnemonic_line.nbr_args ; i++) {
        int param_type = which_param(params[i + 1]);
        if (first_str[my_strlen(first_str) - 1] == ':') {
            param_type = which_param(params[i + 2]);
        }
        if ((mnemonic_line.type[i] & param_type) == 0 || param_type == 0 || \
param_type == -84) {
            return false;
        }
    }
    return true;
}

bool len_handling(char *mnemonic, int tab_len, char *first_str)
{
    op_t mnemonic_line;
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(mnemonic, op_tab[i].mnemonique) == 0) {
            mnemonic_line = op_tab[i];
        }
    }
    if (mnemonic_line.nbr_args == tab_len - 1) {
        return true;
    }
    if (first_str[my_strlen(first_str) - 1] == ':' && mnemonic_line.nbr_args \
== tab_len - 2) {
        return true;
    }
    return false;
}

int len_and_type_checker_2(line_t *line, int i, int j)
{
    if (is_mnemonic(line[i].tokens[j]) == true) {
        if (len_handling(line[i].tokens[j], len_tab(line[i].tokens), \
line[i].tokens[0]) == false)
            return 84;
        if (good_param_type(line[i].tokens[j], line[i].tokens) == false)
            return 84;
    }
    return 0;
}

int len_and_type_checker(line_t *line, int i)
{
    for (int j = 0; line[i].tokens[j] != NULL; j++){
        if (len_and_type_checker_2(line, i, j) == 84)
            return 84;
        if (my_strcmp(line[i].tokens[j], NAME_CMD_STRING) == 0 && \
line[i].tokens[j + 1] != NULL) {
        }
    }
    return 0;
}

int mnemonic_and_params_checker(line_t *line, int nb_lines)
{
    parameter_t *param = malloc(sizeof(parameter_t) * nb_lines);
    int size = 0, i = 0;
    for (; line[i].tokens != NULL; i++) {
        if (len_and_type_checker(line, i) == 84) {
            return -84;
        }
        if (line[i].tokens[0] == NULL)
            continue;
        if (is_mnemonic(line[i].tokens[0]) == false && \
line[i].tokens[0][0] != 10 && my_strcmp(line[i].tokens[0], NAME_CMD_STRING) \
!= 0 && my_strcmp(line[i].tokens[0], COMMENT_CMD_STRING) != 0 && \
label_char_checker(line[i].tokens[0]) == true) {
            return -84;
        }
    }
    param_filler(line, param);
    size = prog_size_calculator(param, nb_lines);
    return size;
}
