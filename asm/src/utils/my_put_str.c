/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-elliot.masina
** File description:
** my_put_str
*/


/* system INCLUDES */
#include <unistd.h>


int my_put_strerr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (write(2, &str[i], 1) == -1)
            return 84;
    }
    return 0;
}

int my_put_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (write(1, &str[i], 1) == -1)
            return 84;
    }
    return 0;
}
