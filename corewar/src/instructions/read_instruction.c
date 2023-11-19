/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** read instuctions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

int get_current_opcode(corewar_t *core, champion_t *champ)
{
    int pc = champ->pc;
    unsigned char opcode = core->arena[pc];

    if (opcode < 1 || opcode > 16)
        return ERROR;
    return (int)opcode;
}

int read_argument(corewar_t *core, int pc, args_type_t arg_type, int *arg_value)
{
    *arg_value = 0;

    switch (arg_type) {
        case T_REG:
            *arg_value = core->arena[pc++];
            break;
        case T_DIR:
            for (int j = 0; j < DIR_SIZE; j++) {
                *arg_value = (*arg_value << 8) | (core->arena[pc++] & 0xFF);
            }
            break;
        case T_IND:
            for (int j = 0; j < IND_SIZE; j++) {
                *arg_value = (*arg_value << 8) | (core->arena[pc++] & 0xFF);
            }
            break;
        default:
            return ERROR;
    }
    return pc;
}

int allocate_argument(argument_t **arg)
{
    *arg = malloc(sizeof(argument_t));
    if (*arg == NULL) {
        my_put_strerr("ERROR (allocate_argument): malloc arg.\n");
        return ERROR;
    }
    return SUCCESS;
}

int read_instruction(corewar_t *core, champion_t *champ, instruction_t *instru)
{
    if (core == NULL || champ == NULL || instru == NULL || !champ->is_alive)
        return (core && champ && instru) ? SUCCESS : ERROR;
    int opcode = get_current_opcode(core, champ);
    op_t op = op_tab[opcode - 1];
    instru->opcode = opcode;
    for (int i = 0; i < op.nbr_args; i++) {
        argument_t *arg;
        if (allocate_argument(&arg) == ERROR)
            return ERROR;
        int pc = champ->pc;
        args_type_t arg_type = op.type[i];
        int arg_value = 0;
        if ((pc = read_argument(core, pc, arg_type, &arg_value)) == ERROR) {
            kill_champ(core, champ);
            return SUCCESS;
        }
        arg->type = arg_type; arg->value = arg_value; instru->args[i] = arg;
    }
    return SUCCESS;
}
