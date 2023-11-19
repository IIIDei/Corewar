/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** printf
*/

#include "lib.h"
#include "my_printf.h"

int int_conv(unsigned int nbr, int base, char *tab)
{
    int count = 0;

    if ((nbr / base) != 0) {
        count += int_conv((nbr / base), base, tab);
        my_putchar(tab[nbr % base]);
        return (count + 1);
    } else {
        my_putchar(tab[nbr % base]);
        count++;
    }
    return (count);
}

int dec_to_octal(unsigned int nbr)
{
    int count = int_conv(nbr, 8, "01234567");
    return count;
}

int dec_to_dec(unsigned int nbr)
{
    int count = int_conv(nbr, 10, "0123456789");
    return count;
}

int dec_to_hexa(unsigned int nbr)
{
    int count = int_conv(nbr, 16, "0123456789abcdef");
    return count;
}

int dec_to_majhexa(unsigned int nbr)
{
    int count = int_conv(nbr, 16, "0123456789ABCDEF");
    return count;
}
