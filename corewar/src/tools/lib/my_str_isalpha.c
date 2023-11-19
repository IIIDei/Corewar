/*
** EPITECH PROJECT, 2023
** gdubernat
** File description:
** between a and z or A and Z
*/

#include <stdbool.h>

bool my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z')
        && !(str[i] >= 'A' && str[i] <= 'Z')) {
            return false;
        }
    }
    return true;
}
