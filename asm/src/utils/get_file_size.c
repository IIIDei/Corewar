/*
** EPITECH PROJECT, 2023
** get the file of a file
** File description:
** get_file_size
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

long get_file_size(char const *filepath)
{
    int fd;
    long size = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    size = lseek(fd, 0, SEEK_END);
    close(fd);
    return size;
}
