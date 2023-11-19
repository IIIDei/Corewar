/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** free all
*/

/* LOCAL INCLUDES */
#include "corewar.h"
#include "op.h"
#include "lib.h"

void free_corewar(corewar_t *core)
{
    if (core == NULL)
        return;
    if (core->arena != NULL)
        free(core->arena);
    if (core->champ != NULL) {
        for (int i = 0; i < core->nb_champs; i++) {
            free(core->champ[i]->body);
        }
        free(core->champ);
    }
    free(core);
}
