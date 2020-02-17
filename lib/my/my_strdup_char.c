/*
** EPITECH PROJECT, 2019
** my_strdup_char
** File description:
** Char to str
*/

#include <stdlib.h>

char *my_strdup_char(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = '\0';
    return (str);
}
