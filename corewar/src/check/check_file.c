/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** check_file
*/


/* system INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "utils.h"
#include "lib.h"
#include "print.h"
#include "corewar.h"

int check_path(char const *path)
{
    int i = 0;

    for (; path[i]; i++);
    if (i <= 4 || my_strcmp(path + (i - 4), ".cor") != 0) {
        my_put_strerr("Incorect file extension. \".cor\" needed.\n");
        return ERROR;
    }
    return SUCCESS;
}

int check_file(char const *arg)
{
    FILE *stream = fopen(arg, "r");

    if (stream == NULL) {
        my_put_strerr("Error: Cannot open or read file.\n");
        return ERROR;
    }
    if (fclose(stream) == ERROR) {
        my_put_strerr("Error: Cannot close file.\n");
        return ERROR;
    }
    return SUCCESS;
}
