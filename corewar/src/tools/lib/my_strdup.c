/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** cp + malloc a string
*/

#include "lib.h"

char *my_strdup(const char *s)
{
    size_t len = my_strlen(s);
    char *dest = malloc(sizeof(char) * (len + 1));

    if (dest == NULL) {
        return NULL;
    }
    for (size_t i = 0; i <= len; i++) {
        dest[i] = s[i];
    }
    return dest;
}
