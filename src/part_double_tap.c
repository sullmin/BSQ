/*
** EPITECH PROJECT, 2019
** pat.c
** File description:
** BSQ
*/

#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"
#include "my.h"

int *line_cnt(char *temp)
{
    int i = 0;
    int nb = 0;
    int etat = 1;
    int f_line = fs_get_number_from_first_line(temp);
    int *tab = malloc(sizeof(int) * (f_line + 2));

    if (f_line < 0)
        return NULL;
    tab[0] = f_line;
    for (i = 0; temp[i] != '\n'; i++);
    for (i = i + 1; temp[i - 1] != '\0'; i++) {
        nb++;
        if (temp[i] == '\n' || temp[i] == '\0') {
            tab[etat] = nb;
            etat++;
            nb = 0;
        }
    }
    return tab;
}

static bool chek_tab(int *tab)
{
    for (int i = 1; i < tab[0]; i++)
        if (tab[i] != tab[i + 1])
            return false;
    return true;
}

int **make_matr(char *temp, int *tab)
{
    int u = 0;
    int x = 0;
    int y = 0;
    int **matrix = malloc(sizeof(int *) * (tab[0] + 1));

    if (matrix == NULL || (!(chek_tab(tab))))
        return NULL;
    for (int u = 0; u < tab[0]; u++)
        matrix[u] = malloc(sizeof(int) * (tab[1]));
    for (u = 0; temp[u] != '\n'; u++);
    for (int i = u + 1; temp[i] != '\0'; i++) {
        matrix[x][y] = (temp[i] == '.') ? 1 : 0;
        y++;
        if (temp[i + 1] == '\n') {
            i++;
            x++;
            y = 0;
        }
    }
    return matrix;
}