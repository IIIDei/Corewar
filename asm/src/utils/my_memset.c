/*
** EPITECH PROJECT, 2023
** my_memset
** File description:
** my_memset
*/

void *my_memset(void *string, int value, int len)
{
    unsigned char *p = string;
    while (len-- > 0) {
        *p++ = (unsigned char)value;
    }
    return string;
}
