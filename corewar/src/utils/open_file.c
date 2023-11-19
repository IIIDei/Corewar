/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** get_fd
*/

/* system INCLUDES */
#include <fcntl.h>

/* LOCAL INCLUDES */
#include "macro.h"
#include "utils.h"

int open_file(const char *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_put_strerr("Error (get_fd) : can't open the file.\n");
        return ERROR;
    }
    return fd;
}
