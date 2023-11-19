/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

static int is_a_character(char c)
{
    if (c != '\n') {
        return 1;
    } else {
        return 0;
    }
}

static int	count_wd_num(char const *str)
{
    int	a = 0;
    int	b = 0;
    while (str[a] != '\0') {
        if (str[a] == '\n'){
            b = b + 1;
        }
        a = a + 1;
    }
    if (str[a - 1] != '\n') {
        return (b * 2 + 1);
    } else {
        return (b * 2);
    }
}

static int len_of_word(char const *str, int i)
{
    int a = i;
    while (str[i] != '\0') {
            if (is_a_character(str[i]) != 1){
                    return (i - a);
            }
            i++;
    }
    return (i - a);
}

static int space_cor(char const *str, int i)
{
    while (str[i] != '\0' && is_a_character(str[i]) != 1) {
        i++;
    }
    return i;
}

char **my_line_to_word_array(const char *str)
{
    int num_words = count_wd_num(str), a = space_cor(str, 0), b = 0, c = 0;
    char **result = malloc(sizeof(char *) * (num_words + 1));
    while (b < num_words) {
        c = 0;
        result[b] = malloc(sizeof(char) * (len_of_word(str, a) + 1));
        while (str[a] != '\0' && is_a_character(str[a])) {
            result[b][c++] = str[a++];
        }
        result[b][c] = '\0';
        b++;
        if (str[a] == '\n') {
            result[b] = malloc(sizeof(char) * 2);
            result[b][0] = '\n';
            result[b][1] = '\0';
            b++;
            a++;
        }
    }
    result[b] = NULL;
    return result;
}
