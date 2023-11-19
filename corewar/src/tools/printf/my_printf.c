/*
** EPITECH PROJECT, 2022
** gdubernat
** File description:
** printf
*/

#include "lib.h"
#include "my_printf.h"

static int dec_to_binary(unsigned int nbr)
{
    int count = int_conv(nbr, 2, "01");
    return count;
}

static int sp_charact(const char *format, int i, va_list lst)
{
    int count = 0;
    if (format[i] == '%')
        count += my_putchar('%');
    if (format[i] == 'd' || format[i] == 'i')
        count = my_put_nbr(va_arg(lst, int));
    if (format[i] == 's')
        count = my_putstr(va_arg(lst, char *));
    if (format[i] == 'c')
        count += my_putchar(va_arg(lst, int));
    if (format[i] == 'o')
        count = dec_to_octal(va_arg(lst, int));
    if (format[i] == 'u')
        count = dec_to_dec(va_arg(lst, int));
    if (format[i] == 'x')
        count = dec_to_hexa(va_arg(lst, int));
    if (format[i] == 'X')
        count = dec_to_majhexa(va_arg(lst, int));
    if (format[i] == 'b')
        count = dec_to_binary(va_arg(lst, int));
    return count;
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    va_list lst;
    va_start(lst, format);
    if (format == NULL)
        return -1;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            count += sp_charact(format, i, lst);
        } else {
            my_putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(lst);
    return count;
}
