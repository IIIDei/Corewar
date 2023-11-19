/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** init arena
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"

int init_arena(corewar_t *core)
{
    if (core == NULL)
        return ERROR;
    core->arena = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        core->arena[i] = 0;
    return SUCCESS;
}
