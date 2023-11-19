/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** check_arg
*/

/* system INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "utils.h"
#include "print.h"

static int check_file(char const *arg)
{
    size_t size = 0; ssize_t nread = 0; char *buf = NULL; char *str = NULL;
    FILE *stream = fopen(arg, "r");

    if (stream == NULL || (str = malloc(sizeof(char) * 1)) == NULL) {
        my_put_strerr("Error: Cannot open, read file or alloc buffer.\n");
        return ERROR;
    }
    str[0] = '\0';
    while ((nread = getline(&buf, &size, stream)) != -1) {
        if ((str = realloc(str, sizeof(char) * (my_strlen(str) + \
my_strlen(buf) + 1))) == NULL) {
            my_put_strerr("Error: Cannot realloc buffer.\n");
            return ERROR;
        }
        my_strcat(str, buf);
    } if (fclose(stream) == ERROR) {
        my_put_strerr("Error: Cannot close file.\n");
        return ERROR;
    }
    return SUCCESS;
}

static int check_path(char const *path)
{
    int i = 0;

    for (; path[i]; i++);

    if (i <= 2 || my_strcmp(path + i - 2, ".s") != 0) {
        my_put_strerr("Incorect file extension. \".s\" needed.\n");
        return ERROR;
    }

    return SUCCESS;
}

int check_arg(int const argc, char const *argv[])
{
    if (argc != 2) {
        my_put_strerr("Error: Bad arguments.\n");
        return ERROR;
    } if (my_strcmp(argv[1], "-h") == 0) {
        if (print_help() == ERROR)
            return ERROR;
        return SUCCESS;
    }
    if (check_path(argv[1]) == ERROR
    || check_file(argv[1]) == ERROR)
        return ERROR;
    return SUCCESS;
}
