/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** Instruction : live
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "my_printf.h"

int exec_live(corewar_t *core, champion_t *champ, int arg)
{
    if (core == NULL || champ == NULL)
        return ERROR;
    arg = arg;
    core->last_alive = champ->id;
    champ->nb_live++;
    champ->live_before_die = true;
    my_printf("The player %d(%s)is alive.\n", champ->id, champ->name);
    return SUCCESS;
}
