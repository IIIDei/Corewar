/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** print_help
*/


/* LOCAL INCLUDES */
#include "macro.h"
#include "utils.h"


int print_help(void)
{
    if (my_put_str("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in"
    " assembly language to be converted into file_name.cor, an\nexecutable in "
    "the Virtual Machine.\n\n") == ERROR)
        return ERROR;
    return SUCCESS;
}
