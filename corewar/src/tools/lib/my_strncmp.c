/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** return 0 if equal
*/

#include "lib.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    if (s1 == NULL || s2 == NULL)
        return 84;
    for (size_t i = 0; *s1 && *s2 && i != n; i++) {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return 0;
}
