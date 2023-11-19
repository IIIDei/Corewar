/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** my_memcpy
*/

#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *destination;
    const unsigned char *source;

    if (dest == NULL || src == NULL)
        return NULL;
    destination = dest;
    source = src;
    for (size_t i = 0; i < n; i++)
        destination[i] = source[i];
    return dest;
}
