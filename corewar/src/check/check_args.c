/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** check_args
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

static int check_flags(corewar_t *core, int const argc, char *argv[], int i)
{
    if (i + 1 >= argc) {
        my_put_strerr("Error: Invalid number of arguments.\n");
        return ERROR;
    }
    if (my_strcmp(argv[i], "-dump") == 0) {
        if (set_dump_value(core, argv, i) == ERROR)
            return ERROR;
        return SUCCESS;
    }
    if (my_strcmp(argv[i], "-n") == 0)
        return SUCCESS;
    if (my_strcmp(argv[i], "-a") == 0)
        return SUCCESS;
    my_put_strerr("Error: Invalid argument.\n");
    return ERROR;
}

static int check_loop(corewar_t *core, int const argc, char *argv[], int i)
{
    if (argv[i][0] == '-') {
        if (check_flags(core, argc, argv, i) == ERROR)
            return ERROR;
        return 1;
    } else {
        if (check_path(argv[i]) == ERROR || check_file(argv[i]) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int check_args(corewar_t *core, int const argc, char *argv[])
{
    int result = 0;

    if (argc < 2) {
        my_put_strerr("Error: Bad arguments.\n");
        return ERROR;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        if (print_help() == ERROR)
            return ERROR;
        return SUCCESS;
    }
    for (int i = 1; i < argc; i++) {
        result = check_loop(core, argc, argv, i);
        if (result == ERROR)
            return ERROR;
        i = i + result;
    }
    return SUCCESS;
}
