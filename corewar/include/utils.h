/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** utils
*/

#include <stddef.h>
#include <stdlib.h>

#ifndef UTILS_H_
    #define UTILS_H_
    int my_put_str(char const *str);
    int my_put_strerr(char const *str);
    void *my_memcpy(void *dest, const void *src, size_t n);
    int open_file(const char *filepath);
    int my_get_nbr(char *valeur);
#endif /* !UTILS_H_ */
