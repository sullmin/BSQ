/*
** EPITECH PROJECT, 2019
** first_line.c
** File description:
** BSQ
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

/*static char *fs_take_first_line(char const *filepath)
{
    int i = 0;
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 2048 + 1);
    char *temp = malloc(sizeof(char) * 2048 + 1);
    int a = 1;

    buffer[2048] = '\0';
    buffer[0] = '1';
    while (buffer[i] != '\0' && buffer[i] != '\n') {
        a = read(fd, buffer, 2048);
        for (i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++)
            temp[i] = buffer[i];
    }
    if (buffer[i] == '\0')
        temp[0] = 'A';
    temp[i] = '\0';
    free(buffer);
    return temp;
}*/

static char *fs_take_first_line(char const *temp)
{
    int i;
    char *string_return;

    for (i = 0; temp[i] != '\0' && temp[i] != '\n'; i++);
    if (temp[i] == '\0')
        return NULL;
    string_return = malloc(sizeof(char) * (i + 1));
    for (i = 0; temp[i] != '\0' && temp[i] != '\n'; i++)
        string_return[i] = temp[i];
    string_return[i] = '\0';
    return string_return;
}

int fs_get_number_from_first_line(char const *temp)
{
    int v_temp;
    char *first_line = fs_take_first_line(temp);

    if (my_str_isnum(first_line) == 1 && first_line[0] != '\0') {
        v_temp = my_getnbr(first_line);
        free(first_line);
        return v_temp;
    }
    else {
        free(first_line);
        return -1;
    }
}