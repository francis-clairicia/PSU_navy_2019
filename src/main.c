/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "navy.h"
#include "my.h"

static int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the positions of the ships.\n");
    return (0);
}

int main(int ac, char *av[])
{
    if (ac > 3)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_help());
}