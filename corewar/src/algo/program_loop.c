/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** program_loop
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

static int reset_champs(corewar_t *core)
{
    for (int i = 0; i < core->nb_champs; i++) {
        champion_t *current_champ = core->champ[i];
        if (!current_champ->is_alive)
            continue;
        if ((!current_champ->live_before_die)
        || (current_champ->nb_live < NBR_LIVE)) {
            kill_champ(core, current_champ);
        } else {
            current_champ->nb_live = 0;
            current_champ->live_before_die = false;
        }
    }
    return SUCCESS;
}

static int cycle_part(corewar_t *core)
{
    if (core->cycle_count == core->cycle_to_die) {
        reset_champs(core);
        core->cycle_count = -1;
        core->cycle_to_die -= CYCLE_DELTA;
        if (core->cycle_to_die <= 0) {
            my_put_strerr("core->cycle_to_die <= 0.\n");
            my_printf("No Winner!\n");
            return ERROR;
        }
    }
    core->cycle_count++;
    return SUCCESS;
}

static int handle_champ(corewar_t *core, champion_t *current_champ,
instruction_t *instru)
{
    if (current_champ->cycle_to_wait == -1)
        set_cycle_to_wait(core, current_champ);
    if (current_champ->cycle_to_wait == 0) {
        if (read_instruction(core, current_champ, instru) == ERROR)
            return ERROR;
        if (game_end_condition(core))
            return SUCCESS;
        if (exec_instruction(core, current_champ, instru) == ERROR)
            return ERROR;
        if (game_end_condition(core))
            return SUCCESS;
        set_cycle_to_wait(core, current_champ);
    }
    if (game_end_condition(core))
        return SUCCESS;
    current_champ->cycle_to_wait--;
    return SUCCESS;
}

static int champion_part(corewar_t *core, instruction_t *instru)
{
    for (int i = 0; i < core->nb_champs; i++) {
        champion_t *current_champ = core->champ[i];
        if (!current_champ->is_alive)
            continue;
        if (handle_champ(core, current_champ, instru) == ERROR)
            return ERROR;
    }
    if (core->dump_cycles > 0)
        core->dump_cycles--;
    return SUCCESS;
}

int program_loop(corewar_t *core, instruction_t *instru)
{
    if (core == NULL || instru == NULL)
        return ERROR;
    while (core->nb_alive_champ > 1) {
        if (core->dump_cycles == 0) {
            display_arena(core->arena);
            core->dump_cycles = -1;
        }
        if (champion_part(core, instru) == ERROR)
            return ERROR;
        if (game_end(core))
            return SUCCESS;
        if (cycle_part(core) == ERROR)
            return ERROR;
        if (game_end(core))
            return SUCCESS;
    }
    if (!game_end(core))
        my_printf("No winner.\n");
    return SUCCESS;
}
