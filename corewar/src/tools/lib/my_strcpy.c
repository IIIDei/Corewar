/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** return a copy of a sting
*/

#include "lib.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL) {
        my_put_error("Error (my_strcpy): destination/source string is NULL.\n");
        return NULL;
    }
    for (; src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
