/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** return 0 if equal
*/

#include "lib.h"

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
