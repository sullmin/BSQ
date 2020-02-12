/*
** EPITECH PROJECT, 2019
** BSQ.h
** File description:
** BSQ
*/

#ifndef MY_BSQ
#define MY_BSQ

int fs_get_number_from_first_line(char const *filepath);
int *square_finder(int **matrix, int *tab);
char *files_read(char const *filepath);
int **make_matr(char *temp, int *tab);
int *line_cnt(char *temp);
void x_print_square(char *temp, int *max_size, int *tab);
int files_size(char const *filepath);
int min_val(int **matrix, int x, int y);
int find_mod(int **matrix, int x, int y);

#endif