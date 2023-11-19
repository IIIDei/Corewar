/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** my_str_to_word_array_comma
*/

#include <stdlib.h>
#include <stdio.h>

static int is_a_character_comma(char c)
{
    if ((c > ' ' && c <= '~') || c == '\n') {
        return 1;
    } else {
        return 0;
    }
}

static int count_word_number_comma(char const *str)
{
    int	a = 0;
    int	b = 0;
    while (str[a] != '\0') {
        if (is_a_character_comma(str[a]) == 1 && \
is_a_character_comma(str[a + 1]) == 0) {
            b = b + 1;
        }
        a = a + 1;
    }
    return (b);
}

static int len_of_word_comma(char const *str, int i)
{
    int a = i;
    while (str[i] != '\0') {
            if (is_a_character_comma(str[i]) != 1) {
                    return (i - a);
            }
            i++;
    }
    return (i - a);
}

static int space_correction_comma(char const *str, int i)
{
    while (str[i] != '\0' && is_a_character_comma(str[i]) != 1) {
        i++;
    }
    return i;
}

char **my_str_to_word_array_comma(char const *str)
{
    int y = count_word_number_comma(str);
    char **result = malloc(sizeof(char *) * (y + 1));
    int a = space_correction_comma(str, 0), b = 0, c = 0;
    while (b < y){
        c = 0;
        result[b] = malloc(sizeof(char) * (len_of_word_comma(str, a) + 1));
        while (str[a] != '\0' && is_a_character_comma(str[a]) != 0) {
            result[b][c] = str[a];
            c = c + 1;
            a = a + 1;
        }
        result[b][c] = '\0';
        a = space_correction_comma(str, a);
        b = b + 1;
    }
    result[b] = NULL;
    return result;
}
