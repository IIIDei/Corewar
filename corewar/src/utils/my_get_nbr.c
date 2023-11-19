/*
** EPITECH PROJECT, 2023
** my_get_nbr
** File description:
** my_get_nbr
*/

int my_get_nbr(char *valeur)
{
    int i = 0;
    int nombre = 0;
    int mul = 1;
    int sign = 1;
    if (valeur[0] == '-') {
        sign = -1;
        i++;
    }
    while (valeur[i] != '\0') {
        nombre = nombre * mul + (valeur[i] - '0');
        mul = 10;
        i++;
    }
    return nombre * sign;
}
