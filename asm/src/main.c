/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** main
*/

/* system INCLUDES */
#include <stdio.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "op.h"
#include "asm.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    if (check_arg(argc, argv) == ERROR)
        return EPITECH_ERROR;
    if (line_to_word_split(argv[1]) == NULL)
        return 84;
    return SUCCESS;
}
