/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** my_get_nbr
*/

#include "lib.h"

int get_nbr(char *charact)
{
    int nb = 0;
    int size = my_strlen(charact);

    if (size == 1)
        return *charact - 48;
    if (charact[0] == '-') {
        for (int i = 1; i < size; i++)
            nb = (nb * 10) + (charact[i] - 48);
        return nb *= -1;
    } else {
        for (int i = 0; i < size; i++)
            nb = (nb * 10) + (charact[i] - 48);
        return nb;
    }
    return nb;
}
