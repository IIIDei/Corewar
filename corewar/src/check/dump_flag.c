/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** -dump flag
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

int set_dump_value(corewar_t *core, char *argv[], int i)
{
    int dump_value = 0;

    if (core == NULL)
        return ERROR;

    dump_value = my_get_nbr(argv[i + 1]);
    if (dump_value <= 0) {
        my_put_strerr("Invalid value for -dump flag.\n");
        return ERROR;
    }
    core->dump_cycles = dump_value;
    return SUCCESS;
}
