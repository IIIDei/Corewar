/*
** EPITECH PROJECT, 2023
** calculate the lenght of a 2d array
** File description:
** len_tab
*/
#include <stdlib.h>

int len_tab(char *const *const tab)
{
    int len = 0;
    for (int i = 0; (tab[i] != NULL); i++) {
        len++;
    }
    return len;
}
