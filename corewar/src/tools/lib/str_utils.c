/*
** EPITECH PROJECT, 2023
** gdubernat
** File description:
** functions for str
*/

#include "lib.h"

static bool letter_is_separator(char const letter, char *const separator)
{
    for (int i = 0; separator[i]; i++) {
        if (separator[i] == letter)
            return true;
    }
    return false;
}

int count_words(char *str, char *const separator)
{
    int count = 0;
    bool on_word = false;

    if (str == NULL)
        return -1;
    while (*str) {
        if (!letter_is_separator(*str, separator) && on_word == false) {
            on_word = true;
            count++;
        }
        if (letter_is_separator(*str, separator) && on_word == true) {
            on_word = false;
        }
        str++;
    }
    return count;
}
