/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** my_strcat
*/

#include "lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    if (dest == NULL || src == NULL) {
        my_put_error("Error (my_strcat): destination/source string is NULL.\n");
        return NULL;
    }
    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; i++, j++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return dest;
}
