/*
** EPITECH PROJECT, 2023
** header.c
** File description:
** header
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

char *concatenate_tokens(char **tokens, int start_index)
{
    int total_length = 0;
    for (int i = start_index; tokens[i] != NULL; i++) {
        total_length += my_strlen(tokens[i]) + 1;
    }
    char *result = malloc(total_length + 1);
    my_memset(result, '\0', total_length + 1);
    if (!result) {
        write(1, "error\n", 7);
        return NULL;
    }
    for (int i = start_index; tokens[i] != NULL; i++) {
        my_strcat(result, tokens[i]);
        if (tokens[i + 1] != NULL) {
            my_strcat(result, " ");
        }
    }
    return result;
}

void change_extension_to_cor(char* filename)
{
    int len = my_strlen(filename);

    for (int i = len - 1; i >= 0; --i) {
        if (filename[i] == '.') {
            filename[i] = '\0';
            my_strcat(filename, ".cor");
            break;
        }
    }
    return;
}

uint32_t int_to_big_endian(uint32_t value)
{
    return ((value >> 24) & 0x000000FF) |
            ((value >> 8)  & 0x0000FF00) |
            ((value << 8)  & 0x00FF0000) |
            ((value << 24) & 0xFF000000);
}

void write_header(const char *output_file, header_t header)
{
    FILE *fp = fopen(output_file, "wb");
    uint32_t magic_be = int_to_big_endian(header.magic);
    uint32_t program_size_be = int_to_big_endian(header.prog_size);
    uint32_t zero_padding = 0;
    if (!fp) {
        write(1, "Error opening output file\n", 27);
        return;
    }
    fwrite(&magic_be, sizeof(uint32_t), 1, fp);
    fwrite(header.prog_name, sizeof(char), PROG_NAME_LENGTH, fp);
    fwrite(&zero_padding, sizeof(uint32_t), 1, fp);
    fwrite(&program_size_be, sizeof(int), 1, fp);
    fwrite(header.comment, sizeof(char), COMMENT_LENGTH, fp);

    fclose(fp);
}

header_t header_filler(line_t *line, header_t header, char *filepath, int size)
{
    for (int i = 0; line[i].tokens != NULL; i++) {
        if (line[i].tokens[0] == NULL)
            continue;
        if (my_strcmp(line[i].tokens[0], ".name") == 0) {
            my_full_fill_strncpy(header.prog_name, \
concatenate_tokens(line[i].tokens, 1), PROG_NAME_LENGTH);
        }
        if (my_strcmp(line[i].tokens[0], ".comment") == 0) {
            my_full_fill_strncpy(header.comment, \
concatenate_tokens(line[i].tokens, 1), COMMENT_LENGTH);
        }
    }
    header.magic = COREWAR_EXEC_MAGIC;
    header.prog_size = size;
    change_extension_to_cor(filepath);
    write_header(filepath, header);
    return header;
}
