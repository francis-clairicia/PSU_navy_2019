/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** wait_enemy_turn.c
*/

#include <unistd.h>
#include "navy.h"
#include "my.h"

int wait_enemy_turn(pid_t player_pid, navy_t *my_navy)
{
    vector_t pos;
    int square = 0;
    int status = 0;

    my_putstr("waiting for enemy's attack...\n");
    square = receive_number(player_pid, 7);
    if (square & (1 << 6))
        return (false);
    pos.x = (square >> 3) & 7;
    pos.y = (square >> 0) & 7;
    if (hit_my_navy(my_navy, pos)) {
        status = 1;
        if (all_navy_destroyed(my_navy))
            status = 2;
    }
    if (!send_number(player_pid, status, 2))
        return (false);
    return ((status == 2) ? 2 : true);
}