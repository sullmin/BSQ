/*
** EPITECH PROJECT, 2019
** my_sort_int_array.c
** File description:
** task06
*/

void my_sort_int_array(int *array, int size)
{
    int storage;

    for (int o = 0; o < size - 1; o++) {
        if (array[o + 1] < array[o]) {
            storage = array[o + 1];
            array[o + 1] = array[o];
            array[o] = storage;
            o = -1;
        }
    }
}
