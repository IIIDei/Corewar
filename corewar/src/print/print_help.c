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
    if (my_put_str("USAGE\n./corewar [-dump nbr_cyle] [[-n prog_number] [-a lo"
        "ad_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps the me"
        "mory after the nbr_cycle execution (if the round isn't\nalready over)"
        " with the following format: 32 bytes/line\nin hexadecimal (AOBCDEFE1D"
        "D3...)\n-n prog_number sets the next program's number. By default, t"
        "he first free number \nin the parameter order\n-a load_address sets th"
        "e next program's loading address. When no address is \nspecified, opti"
        "mize the address so that the processes are as far \naway from each as "
        "possible. The addresses are MEM_SIZE modulo.\n\n") == ERROR)
        return ERROR;
    return SUCCESS;
}
