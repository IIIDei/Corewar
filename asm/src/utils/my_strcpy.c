/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** return str cpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int count;
    count = 0;
    while (src[count] != '\0') {
        dest[count] = src[count];
        count += 1;
    }
    dest[count] = '\0';
    return (dest);
}
