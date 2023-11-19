/*
** EPITECH PROJECT, 2023
** all fonctions that check something
** File description:
** is_checker
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

int is_label(const char *token)
{
    int len = 0;
    char *modified_token = NULL;

    len = my_strlen(token);
    modified_token = malloc(sizeof(char) * len);
    my_memset(modified_token, '\0', len);
    if (len > 0 && token[len - 1] == ':') {
        my_strncpy(modified_token, token, len - 1);
        my_put_str(modified_token);
        if (my_str_isalphanum(modified_token) == 1) {
            return 1;
        }
    }
    return 0;
}

bool is_mnemonic(char *token)
{
    int num_mnemonics = 16;

    if (!token)
        return false;

    for (int i = 0; i < num_mnemonics; i++) {
        if (op_tab[i].mnemonique && my_strcmp(token, op_tab[i].mnemonique) \
== 0) {
            return true;
        }
    }
    return false;
}

char *is_comment(char* parsed_file_lines)
{
    for (int j = 0; parsed_file_lines[j] != '\0'; j++) {
        if (parsed_file_lines[j] == '#') {
            parsed_file_lines[j] = '\0';
            return parsed_file_lines;
        }
    }
    return parsed_file_lines;
}

bool label_char_checker_2(char c)
{
    for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
        if (c == LABEL_CHARS[j]) {
            return true;
        }
    }
    return false;
}

bool label_char_checker(char *const potential_label)
{
    for (int i = 0; potential_label[i] != '\0'; i++) {
        if (label_char_checker_2(potential_label[i]) == false)
            return false;
    }
    return true;
}
