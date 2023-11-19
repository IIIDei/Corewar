/*
** EPITECH PROJECT, 2023
** gdubernat
** File description:
** arrays
*/

#include "lib.h"
#include "my_printf.h"

void print_arr(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        my_printf("%s\n", arr[i]);
    }
}

void free_arr(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}

int get_longest_string_length(char **tab)
{
    int max = 0;
    int count = 0;

    if (tab == NULL)
        return -1;
    for (int i = 0; tab[i] != NULL; i++) {
        if ((count = my_strlen(tab[i])) > max) {
            max = count;
            count = 0;
        }
    }
    return max;
}
