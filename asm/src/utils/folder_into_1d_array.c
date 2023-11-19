/*
** EPITECH PROJECT, 2023
** transform a file into a 1d array
** File description:
** folder_into_1d_array
*/
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *folder_into_1d_array(char const *filepath)
{
    int fd;
    char *buffer;
    long file_size = get_file_size(filepath);
    if (file_size == -1) {
        write(1, "FAILURE\n", 9);
        return NULL;
    }
    buffer = malloc(sizeof(char) * (file_size + 1));
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(1, "FAILURE\n", 9);
        free(buffer);
        return NULL;
    }
    read(fd, buffer, file_size);
    buffer[file_size] = '\0';
    close(fd);
    return buffer;
}
