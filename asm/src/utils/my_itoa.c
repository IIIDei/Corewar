/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** my_itoa
*/

#include <stdlib.h>


static int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    return (nb * my_compute_power_rec(nb, p - 1));
}

char *my_itoa(int nb)
{
    if (nb == 0)
        return ("0");
    int i = 0; int j = 0; int nb2 = nb;
    char *str = malloc(sizeof(char) * 100);
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = nb * -1;
    }
    while (nb2 != 0) {
        nb2 = nb2 / 10;
        j++;
    }
    while (j != 0) {
        str[i] = (nb / my_compute_power_rec(10, j - 1)) + 48;
        nb = nb % my_compute_power_rec(10, j - 1);
        i++; j--;
    }
    str[i] = '\0';
    return (str);
}
