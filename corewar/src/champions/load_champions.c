/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** load champions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"

static int insert_champion_body(corewar_t *core, champion_t *champ)
{
    int size, offset;
    void *dest, *src;

    if (core == NULL || champ == NULL)
        return ERROR;
    size = champ->body_size;
    offset = (MEM_SIZE / core->nb_champs) * champ->id;
    dest = core->arena + offset;
    src = champ->body;
    if (my_memcpy(dest, src, size) == NULL)
        return ERROR;
    champ->pc = offset;
    return SUCCESS;
}

int load_champions(corewar_t *core)
{
    for (int i = 0; i < core->nb_champs; i++) {
        if (insert_champion_body(core, core->champ[i]) == ERROR) {
            my_put_strerr("ERROR (load_champions): can't load the champions\n");
            return ERROR;
        }
    }
    return SUCCESS;
}
