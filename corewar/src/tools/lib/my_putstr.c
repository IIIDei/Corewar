/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** disp characters of a string
*/

#include "lib.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int size;
    int nb;

    if (str == NULL)
        return -1;
    size = my_strlen(str);
    if (size == -1)
        return -1;
    nb = write(1, str, size);
    return nb;
}
