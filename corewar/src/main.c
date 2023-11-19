/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** main function
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

static int load_and_algo(corewar_t *core, instruction_t *instru)
{
    if (load_champions(core) == ERROR)
        return ERROR;
    if (read_instruction(core, core->champ[0], instru) == ERROR)
        return ERROR;
    if (program_loop(core, instru) == ERROR)
        return ERROR;
    return SUCCESS;
}

static int init_all(char **argv, corewar_t *core, instruction_t *instru)
{
    if (core == NULL || instru == NULL)
        return ERROR;
    if (init_core(core) == ERROR)
        return ERROR;
    if (init_instruction(instru) == ERROR)
        return ERROR;
    if (init_arena(core) == ERROR)
        return ERROR;
    if (init_champions(core, argv) == ERROR)
        return ERROR;
    if ((core->nb_alive_champ = get_nb_alive_champ(core)) == ERROR)
        return ERROR;
    return SUCCESS;
}

int main(int argc, char **argv)
{
    corewar_t *core = malloc(sizeof(corewar_t));
    instruction_t *instru = malloc(sizeof(instruction_t));

    core->dump_cycles = -1;
    if (core == NULL || instru == NULL)
        return EPITECH_ERROR;
    if (check_args(core, argc, argv) == ERROR)
        return EPITECH_ERROR;
    if (set_nb_champ(core, argv) == ERROR)
        return EPITECH_ERROR;
    if (init_all(argv, core, instru) == ERROR)
        return EPITECH_ERROR;
    if (game_end(core))
        return SUCCESS;
    if (load_and_algo(core, instru) == ERROR)
        return EPITECH_ERROR;
    free_corewar(core);
    return SUCCESS;
}
