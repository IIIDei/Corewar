/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** set cycle
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

int get_instruction_cycle(int opcode)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (op_tab[i].code == opcode) {
            return op_tab[i].nbr_cycles;
        }
    }
    return ERROR;
}

int set_cycle_to_wait(corewar_t *core, champion_t *champ)
{
    int opcode;
    int cycle_to_wait;

    if (champ->is_alive == false)
        return SUCCESS;
    opcode = get_current_opcode(core, champ);
    if (opcode == ERROR) {
        kill_champ(core, champ);
        return SUCCESS;
    }
    cycle_to_wait = get_instruction_cycle(opcode);
    if (cycle_to_wait == ERROR) {
        kill_champ(core, champ);
        return SUCCESS;
    }
    champ->cycle_to_wait = cycle_to_wait;
    return SUCCESS;
}
