/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_memset.c
*/

#include <stddef.h>

char *my_memset(char *buffer, char c, unsigned long size)
{
    unsigned int i = 0;

    if (buffer == NULL)
        return (NULL);
    while (i < size) {
        buffer[i] = c;
        i += 1;
    }
    return (buffer);
}