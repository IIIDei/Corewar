/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** my_str_cat
*/




char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int dest_len = 0;

    for (; dest[dest_len] != '\0'; dest_len++);

    for (; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';
    return (dest);
}
