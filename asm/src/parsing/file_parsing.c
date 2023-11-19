/*
** EPITECH PROJECT, 2023
** file parsing
** File description:
** file_parsing
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

bool is_reg(char *const param)
{
    if (param[0] != 'r') {
        return false;
    }
    int reg_num = 0;
    for (int i = 1; param[i] != '\0'; i++) {
        if (param[i] < '0' || param[i] > '9') {
            return false;
        }
        reg_num = reg_num * 10 + (param[i] - '0');
    }
    if (reg_num < 1 || reg_num > 16) {
        return false;
    }
    return true;
}

int which_param(char *const param)
{
    if (!param)
        return -84;
    if (param[0] != 'r' && param[0] != '%') {
        return T_IND;
    }
    if (is_reg(param) == true) {
            return T_REG;
    }
    if (param[0] == '%') {
        return T_DIR;
    }
    return 0;
}

uint8_t find_opcode(const char *mnemonic)
{
    for (size_t i = 0; i < 16; i++) {
        if (my_strcmp(mnemonic, mnemonic_opcode_map[i].mnemonic) == 0) {
            return mnemonic_opcode_map[i].opcode;
        }
    }
    return 0;
}

void write_instruction_to_file(FILE *file, const char *mnemonic)
{
    uint8_t opcode = find_opcode(mnemonic);
    if (opcode == 0) {
        my_put_str("Unknown mnemonics: ");
        my_put_str(mnemonic);
        my_put_str("\n");
        return;
    }
    fwrite(&opcode, 1, 1, file);
    return;
}

line_t* line_to_word_split(char *const filepath)
{
    int i = 0; int return_value = 0;
    header_t header;
    char *file_parse = folder_into_1d_array(filepath);
    char **parsed_file_line = my_line_to_word_array(file_parse);
    parsed_file_line = remove_comments(parsed_file_line);
    int number_of_line = len_tab(parsed_file_line);
    line_t *line = malloc(sizeof(line_t) * (number_of_line + 1));
    while (parsed_file_line[i] != NULL) {
        line[i].tokens = parse_wether_its_header(parsed_file_line[i]);
        line[i].token_count = len_tab(line[i].tokens);
        i++;
    }
    line[i].tokens = NULL;
    line[i].token_count = 0;
    if ((return_value = mnemonic_and_params_checker(line, i)) == -84
    || return_value == -1)
        return NULL;
    header_filler(line, header, filepath, return_value);
    return line;
}
