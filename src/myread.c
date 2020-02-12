/*
** EPITECH PROJECT, 2019
** read.c
** File description:
** BSQ
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
//#include "bsq.h"

int get_file_size(char const *filepath)
{
    struct stat test;

    if (stat(filepath, &test) == -1)
        return -1;
    return test.st_size;
}

char *files_read(char const *filepath)
{
    char *temp;
    int file_size;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return NULL;
    file_size = get_file_size(filepath);
    if (file_size == -1 || file_size == 0)
        return NULL;
    temp = malloc(sizeof(char) * (file_size + 1));
    if (temp == NULL)
        return NULL;
    temp[file_size] = '\0';
    if (read(fd, temp, file_size) < 0)
        return NULL;
    close(fd);
    return temp;
}