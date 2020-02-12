/*
** EPITECH PROJECT, 2019
** algo2
** File description:
** bsq
*/

#include "my.h"

int min_val(int **matrix, int x, int y)
{
    int tab[3];

    tab[0] = matrix[y][x + 1];
    tab[1] = matrix[y + 1][x];
    tab[2] = matrix[y][x];
    my_sort_int_array(tab, 3);
    return tab[0] + 1;
}

int find_mod(int **matrix, int x, int y)
{
    if (matrix[y][x + 1] != 0 && matrix[y + 1][x] != 0
        && matrix[y + 1][x + 1] != 0 && matrix[y][x] != 0) {
        matrix[y + 1][x + 1] = min_val(matrix, x, y);
    }
    return matrix[y + 1][x + 1];
}