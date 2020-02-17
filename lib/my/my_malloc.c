/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_malloc.c
*/

#include <stdlib.h>

char *my_memset(char *buffer, char c, unsigned long size);

char *my_malloc(unsigned long size)
{
    return (my_memset(malloc(size), '\0', size));
}