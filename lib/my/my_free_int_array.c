/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_free_int_array.c
*/

#include <stdlib.h>

void my_free_int_array(int **array)
{
    int i = 0;

    if (array == NULL)
        return;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
}