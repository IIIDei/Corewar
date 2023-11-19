/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** init champions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "lib.h"
#include "my_printf.h"
#include "op.h"

void kill_champ(corewar_t *core, champion_t *champ)
{
    core->nb_alive_champ--;
    core->last_alive = champ->id;
    champ->is_alive = false;
}

static int init_registers_and_rest(champion_t *champ)
{
    if (champ == NULL) {
        my_put_strerr("ERROR (init_registers).\n");
        return ERROR;
    }
    for (int i = 0; i < REG_NUMBER; i++) {
        champ->registers[i] = 0;
    }
    champ->registers[0] = champ->id;
    champ->pc = 0;
    champ->carry = 0;
    champ->is_alive = true;
    champ->nb_live = 0;
    champ->live_before_die = false;
    champ->cycle_to_wait = -1;
    return SUCCESS;
}

static int init_champion(champion_t *champ, char *filepath, int idx)
{
    int fd;

    champ->id = idx;
    champ->body = NULL;
    if (champ == NULL || filepath == NULL)
        return ERROR;
    if ((fd = open_file(filepath)) == -1)
        return ERROR;
    if (read_champion(champ, fd) == ERROR) {
        close(fd);
        return ERROR;
    }
    close(fd);
    if (init_registers_and_rest(champ) == ERROR)
        return ERROR;
    return SUCCESS;
}

static int loop_to_init(corewar_t *core, char *str, int idx)
{
    size_t length = my_strlen(str);

    if (length > 4 && (my_strcmp((str + (length - 4)), ".cor")) == 0) {
        if ((core->champ[idx] = malloc(sizeof(champion_t))) == NULL)
            return ERROR;
        if (init_champion(core->champ[idx], str, idx) == ERROR)
            return ERROR;
        return SUCCESS;
    }
    return 1;
}

int init_champions(corewar_t *core, char **argv)
{
    int is_champ = 0;
    int idx = 0;

    if (core == NULL)
        return ERROR;
    for (int i = 1; argv[i]; i++) {
        is_champ = loop_to_init(core, argv[i], idx);
        if (is_champ == ERROR)
            return ERROR;
        if (is_champ == SUCCESS)
            idx++;
    }
    return SUCCESS;
}
