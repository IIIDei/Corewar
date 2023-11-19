/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** init instruction struct
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"

void free_instruction(instruction_t *instru)
{
    if (instru == NULL)
        return;
    for (int i = 0; (i < MAX_ARGS_NUMBER) && (instru->args[i] != NULL); i++) {
        free(instru->args[i]);
        instru->args[i] = NULL;
    }
    free(instru);
}

int init_instruction(instruction_t *instru)
{
    if (instru == NULL)
        return ERROR;
    instru->opcode = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        instru->args[i] = malloc(sizeof(argument_t));
        if (instru->args[i] == NULL) {
            free_instruction(instru);
            return ERROR;
        }
        instru->args[i]->type = 0;
        instru->args[i]->value = 0;
    }
    return SUCCESS;
}
