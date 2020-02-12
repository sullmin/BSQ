/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** bsq
*/

#include <stdlib.h>
#include <stdio.h>
#include "bsq.h"

void my_free(int **matrix, int *tab, int *max_size, char *temp)
{
    free(max_size);
    free(temp);
    for (size_t i = 0; i < (size_t) tab[0]; i++)
        free(matrix[i]);
    free(matrix);
    free(tab);
}

int main(int argc, char **argv)
{
    int *max_size;
    int **matrix;
    int *tab;
    char *temp;

    if (argc < 2)
        return 84;
    temp = files_read(argv[1]);
    if (!temp)
        return 84;
    tab = line_cnt(temp);
    if (!tab)
        return 84;
    matrix = make_matr(temp, tab);
    if (!matrix)
        return 84;
    max_size = square_finder(matrix, tab);
    x_print_square(temp, max_size, tab);
    my_free(matrix, tab, max_size, temp);
    return 0;
}
