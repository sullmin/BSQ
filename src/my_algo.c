/*
** EPITECH PROJECT, 2019
** algo.c
** File description:
** BSQ
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

static int *special_find(int *max_size, int *tab, int **matrix)
{
    for (int y = 0; y < tab[0]; y++) {
        for (int x = 0; x < tab[1]; x++) {
            if (matrix[y][x] == 1)
            {
                max_size[0] = 1;
                max_size[1] = y;
                max_size[2] = x + 1;
                return max_size;
            }
        }
    }
    return max_size;
}

int *square_finder(int **matrix, int *tab)
{
    int temp_size = 0;
    int *max_size = malloc(sizeof(int) * 3);

    if (max_size == NULL)
        return NULL;
    else max_size[0] = 0;
    if (tab[0] == 1 || tab[1] - 1 == 1)
        special_find(max_size, tab, matrix);
    else
        for (int y = 0; y < tab[0] - 1; y++)
            for (int x = 0; x < tab[1] - 2; x++) {
                temp_size = find_mod(matrix, x, y);
                if (temp_size > max_size[0])
                {
                    max_size[0] = temp_size;
                    max_size[1] = x + 2;
                    max_size[2] = y + 2;
                }
            }
    return max_size;
}

static void print_special_square(char *temp, int *max_size, int u, int *tab)
{
    if (tab[0] == 1 || tab[1] - 1 == 1) {
        if (tab[0] == 1)
            temp[u + max_size[2]] = 'x';
        else {
            temp[u + max_size[1] * 2 + 1] = 'x';
        }
    }
    return;
}

static void print_square(char *temp, int *max_size, int u, int test)
{
    int x = 0;
    int y = 0;

    for (int i = u + 1; temp[i] != '\0'; i++) {
        if (temp[i] == '\n') {
            x = 0;
            y++;
            if (max_size[2] - max_size[0] == 0)
                test = 0;
        }
        if ((x + test < max_size[1] + 1 && x + test > max_size[1] - max_size[0])
            && (y < max_size[2] && y > max_size[2] - max_size[0] - 1)) {
            temp[i] = 'x';
        }
        x++;
    }
    return;
}

void x_print_square(char *temp, int *max_size, int *tab)
{
    int u;
    int test = 0;

    for (u = 0; temp[u] != '\n'; u++);
    if ((max_size[2] - max_size[0] == 0) && (!(tab[0] == 1 || tab[1] - 1 == 1)))
        test = 1;
    if ((tab[0] == 1 || tab[1] - 1 == 1) && temp[u + 1] != '.'
        && max_size[0] != 0)
        print_special_square(temp, max_size, u, tab);
    else print_square(temp, max_size, u, test);
    write(1, temp + u + 1, my_strlen(temp + u + 1));
    return;
}