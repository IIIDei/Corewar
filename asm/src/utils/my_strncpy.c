/*
** EPITECH PROJECT, 2023
** gdubernat
** File description:
** cp n characts
*/

#include "utils.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] && i < n; i++) {
        dest[i] = src[i];
    }
    if (n > my_strlen(src)) {
        dest[i] = '\0';
    }
    return dest;
}
