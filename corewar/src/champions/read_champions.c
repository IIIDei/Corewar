/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-corewar-gaetan.dubernat
** File description:
** read champions
*/

/* LOCAL INCLUDES */
#include "macro.h"
#include "corewar.h"
#include "lib.h"
#include "my_printf.h"
#include "op.h"

static int read_champion_body(champion_t *champ, int fd)
{
    if (lseek(fd, 0x890, SEEK_SET) == -1
        || (champ->body = malloc(champ->file_size - 0x890)) == NULL
        || lseek(fd, 0x890, SEEK_SET) == -1
        || read(fd, champ->body, champ->body_size) == -1) {
        my_put_strerr("Error (read_champion_body) lseek, malloc or read.\n");
        return ERROR;
    }
    return SUCCESS;
}

int read_champion(champion_t *champ, int fd)
{
    header_t head;
    int nread = read(fd, &head, sizeof(header_t));

    if (nread < (int)(sizeof(header_t))) {
        my_put_strerr("ERROR : Bad read.\n");
        return ERROR;
    }
    my_strcpy(champ->name, head.prog_name);
    champ->file_size = lseek(fd, 0, SEEK_END);
    champ->body_size = champ->file_size - 0x890;
    if (read_champion_body(champ, fd) == ERROR) {
        free(champ->body);
        return ERROR;
    }
    return SUCCESS;
}
