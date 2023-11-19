/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1
** File description:
** my_str_isalphanum
*/

int my_str_isalphanum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < '0' || str[i] > '9') && (str[i] != '_')) {
            return 1;
        }
    }
    return 0;
}
