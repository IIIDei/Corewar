/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** disp characters of a string (error output)
*/

#include "lib.h"
#include <unistd.h>

int my_put_error(char const *str)
{
    int size;
    int nb;

    if (str == NULL)
        return -1;
    size = my_strlen(str);
    if (size == -1)
        return -1;
    nb = write(2, str, size);
    return nb;
}
