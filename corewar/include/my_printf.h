/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** include lib
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    //PRINTF
    int my_printf(const char *format, ...);
    int int_conv(unsigned int nbr, int base, char *tab);
    int dec_to_octal(unsigned int nbr);
    int dec_to_dec(unsigned int nbr);
    int dec_to_hexa(unsigned int nbr);
    int dec_to_majhexa(unsigned int nbr);

#endif
