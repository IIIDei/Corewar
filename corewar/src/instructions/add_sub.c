/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** Instructions : add + sub
*/

/* system INCLUDES */
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"

bool exec_add(champion_t *champ, int reg1, int reg2, int reg3)
{
    int result;

    if (reg1 < 0 || reg2 < 0 || reg3 < 0)
        return false;
    if (reg1 >= REG_NUMBER || reg2 >= REG_NUMBER || reg3 >= REG_NUMBER)
        return false;
    result = champ->registers[reg1] + champ->registers[reg2];
    if (result == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    champ->registers[reg3] = result;
    return true;
}

bool exec_sub(champion_t *champ, int reg1, int reg2, int reg3)
{
    int result;

    if (reg1 < 0 || reg2 < 0 || reg3 < 0)
        return false;
    if (reg1 >= REG_NUMBER || reg2 >= REG_NUMBER || reg3 >= REG_NUMBER)
        return false;
    result = champ->registers[reg1] + champ->registers[reg2];
    if (result == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    champ->registers[reg3] = result;
    return true;
}
