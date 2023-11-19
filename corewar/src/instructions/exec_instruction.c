/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** exec instuctions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

static void exec_add_sub(champion_t *champ, instruction_t *instru)
{
    int opcode = instru->opcode;
    int arg1 = instru->args[0]->value;
    int arg2 = instru->args[1]->value;
    int arg3 = instru->args[2]->value;

    if (opcode == 4)
        exec_add(champ, arg1, arg2, arg3);
    if (opcode == 5)
        exec_sub(champ, arg1, arg2, arg3);
}

int exec_instruction(corewar_t *core, champion_t *champ, instruction_t *instru)
{
    if (!champ->is_alive)
        return SUCCESS;

    switch (instru->opcode) {
        case 1:
            int arg = instru->args[0]->value;
            exec_live(core, champ, arg);
            break;
        case 4:
        case 5:
            exec_add_sub(champ, instru);
            break;
        default:
            break;
    }
    return SUCCESS;
}
