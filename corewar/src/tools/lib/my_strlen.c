/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** len string
*/

#include "lib.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    for (; str[i]; i++);
    return i;
}
