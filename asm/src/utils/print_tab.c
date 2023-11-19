/*
** EPITECH PROJECT, 2023
** print tab
** File description:
** print_tab
*/


#include <stddef.h>
#include <stdio.h>

#include "utils.h"

int print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; ++i)
        my_put_str(tab[i]);
    return 0;
}
