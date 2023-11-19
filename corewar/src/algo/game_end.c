/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** game_end
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "op.h"
#include "lib.h"
#include "my_printf.h"

bool game_end_condition(corewar_t *core)
{
    int nb_alive_champ = get_nb_alive_champ(core);

    core->nb_alive_champ = nb_alive_champ;
    if (nb_alive_champ == 1)
        return true;
    if (nb_alive_champ <= 0)
        return true;
    return false;
}

bool game_end(corewar_t *core)
{
    int nb_alive_champ = get_nb_alive_champ(core);

    core->nb_alive_champ = nb_alive_champ;
    if (nb_alive_champ == 1) {
        display_winner(core);
        return true;
    }
    if (nb_alive_champ <= 0) {
        display_winner_last_alive(core);
        return true;
    }
    return false;
}
