/*
** EPITECH PROJECT, 2019
** My put str
** File description:
** Display a string
*/

#include <unistd.h>
#include <stddef.h>

int my_strlen(char const *str);

static int putstr_in_fd(int fd, char const *str)
{
    if (str == NULL)
        return (putstr_in_fd(fd, "NULL"));
    return (write(fd, str, my_strlen(str)) != -1);
}

int my_putstr(char const *str)
{
    return (putstr_in_fd(1, str));
}

int my_putstr_error(char const *str)
{
    return (putstr_in_fd(2, str));
}