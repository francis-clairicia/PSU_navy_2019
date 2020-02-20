/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include "navy.h"
#include "my.h"

static int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing ");
    my_putstr("the positions of the ships.\n");
    return (0);
}

static int error_args(int ac, char *av[])
{
    if (ac > 3 || ac == 1)
        return (1);
    if (ac == 3 && !my_str_isnum(av[1]))
        return (1);
    return (0);
}

int main(int ac, char *av[])
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_help());
    if (error_args(ac, av))
        return (84);
    return (navy_game(((ac == 2) ? -1 : my_getnbr(av[1])), av[1 + (ac == 3)]));
}