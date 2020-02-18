/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "navy.h"
#include "my.h"

int navy(pid_t player_pid, char * const *positions)
{
    ship_t ships[4];

    if (!init_ships(ships, positions))
        return (84);
    print_gameboard(ships);
    // if (player_pid < 0)
    //     player_pid = receive_number(16);
    // else
    //     send_number(player_pid, getpid(), 16);
    destroy_ships(ships);
    return (0);
}