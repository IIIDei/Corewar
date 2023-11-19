/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);

    return i;
}
