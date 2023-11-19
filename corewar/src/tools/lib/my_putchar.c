/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** print char
*/

#include "lib.h"
#include <unistd.h>

int my_putchar(char c)
{
    int nb = write(1, &c, 1);

    return nb;
}
