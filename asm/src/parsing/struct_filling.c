/*
** EPITECH PROJECT, 2023
** fill the struct
** File description:
** struct_filling
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

void init_param(parameter_t *param, line_t line, int nb_param, int j)
{
    param[j].mnemonic = line.tokens[0];
    param[j].opcode = find_opcode(line.tokens[0]);
    param[j].type = malloc(sizeof(int) * nb_param);
    param[j].value = malloc(sizeof(int) * nb_param);
}

void assign_param_type_and_value(parameter_t *param, line_t line, \
int nb_param, int j)
{
    for (int param_i = 0; param_i != nb_param; param_i++) {
        param[j].type[param_i] = which_param(line.tokens[param_i + 1]);
        param[j].value[param_i] = get_value(line.tokens[param_i + 1]);
    }
}

void param_filler(line_t *line, parameter_t *param)
{
    int nb_param = 0;
    int j = 0;
    for (int i = 0; line[i].tokens != NULL; i++) {
        if (is_mnemonic(line[i].tokens[0]) == true) {
            nb_param = find_len_optab(line[i].tokens[0]);
            init_param(param, line[i], nb_param, j);
            assign_param_type_and_value(param, line[i], nb_param, j);
            j++;
        }
    }
}

char **parse_wether_its_header(char *old_parse)
{
    if (is_first_word_header(old_parse) == true) {
        return my_str_to_word_array_comma(old_parse);
    }
    return my_str_to_word_array(old_parse);
}

bool is_first_word_header(char *parsed_file)
{
    char **temp_parsing = my_str_to_word_array(parsed_file);
    if (!temp_parsing || !temp_parsing[0]) {
        return false;
    }
    if (my_strcmp(temp_parsing[0], ".name") == 0 || \
my_strcmp(temp_parsing[0], ".comment") == 0) {
        return true;
    } else {
        return false;
    }
}
