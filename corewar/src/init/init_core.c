/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** init struct core
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"

int init_core(corewar_t *core)
{
    if (core == NULL)
        return ERROR;
    core->last_alive = 0;
    core->champ = malloc(sizeof(champion_t*) * (core->nb_champs + 1));
    if (core->champ == NULL)
        return ERROR;
    core->cycle_count = 0;
    core->cycle_to_die = CYCLE_TO_DIE;
    return SUCCESS;
}
