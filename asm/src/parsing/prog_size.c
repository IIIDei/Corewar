/*
** EPITECH PROJECT, 2023
** calculate the progsiz
** File description:
** prog_size
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

bool needs_encoding_byte(const char* instruction)
{
    const char* instructions_with_encoding_byte[] = {
        "ld", "st", "add", "sub", "and", "or", "xor", "lld", "sti", \
"fork", "lldi", "lfork", "aff", NULL
    };
    for (int i = 0; instructions_with_encoding_byte[i] != NULL; ++i) {
        if (my_strcmp(instruction, instructions_with_encoding_byte[i]) == 0) {
            return true;
        }
    }
    return false;
}

int opcode_size_calculator(const char *mnemonic)
{
    int size = needs_encoding_byte(mnemonic) ? 2 : 1;
    return size;
}

int parameter_size_calculator(parameter_t param, int nb_param)
{
    int size = 0;
    for (int index = 0; index != nb_param; index++) {
        if (param.type[index] == 1 || param.type[index] == 2) {
            size += 4;
            continue;
        }
        if (param.type[index] == 4) {
            size += 2;
            continue;
        }
    }
    return size;
}

int prog_size_calculator(parameter_t *param, int i)
{
    int size = 0;
    for (int nb_line = 0; nb_line != i; nb_line++) {
        if (is_mnemonic(param[nb_line].mnemonic) == true) {
            int nb_param = find_len_optab(param[nb_line].mnemonic);
            size += opcode_size_calculator(param[nb_line].mnemonic);
            size += parameter_size_calculator(param[nb_line], nb_param);
        }
    }
    return size;
}
