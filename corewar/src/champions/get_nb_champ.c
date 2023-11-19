/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** get_nb_champ
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "lib.h"

int get_nb_alive_champ(corewar_t *core)
{
    int count = 0;

    if (core == NULL)
        return ERROR;
    for (int i = 0; i < core->nb_champs; i++) {
        if (core->champ[i]->is_alive)
            count++;
    }
    return count;
}

static int get_nb_champ(char **argv)
{
    int count = 0;

    for (int i = 1; argv[i]; i++) {
        size_t length = my_strlen(argv[i]);
        if (length > 4 && (my_strcmp((argv[i] + (length - 4)), ".cor") == 0))
            count++;
    }
    if (count == 0) {
        my_put_strerr("Error : no champ.\n");
        return ERROR;
    }
    return count;
}

int set_nb_champ(corewar_t *core, char **argv)
{
    int nb_champs = 0;

    if (core == NULL)
        return ERROR;
    if ((nb_champs = get_nb_champ(argv)) == ERROR)
        return ERROR;
    if (nb_champs > 4) {
        my_put_strerr("ERROR : too many champ (max 4).\n");
        return ERROR;
    }
    core->nb_champs = nb_champs;
    return SUCCESS;
}
