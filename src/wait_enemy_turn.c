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
    int status = 0;

    my_putstr("waiting for enemy's attack...\n");
    pos.x = receive_number(player_pid, 32);
    usleep(100);
    if (pos.x < 0 || !send_bit(player_pid, true))
        return (false);
    pos.y = receive_number(player_pid, 32);
    usleep(100);
    if (hit_my_navy(my_navy, pos)) {
        status = 1;
        if (all_navy_destroyed(my_navy))
            status = 2;
    }
    if (pos.y < 0 || !send_number(player_pid, status, 2))
        return (false);
    return ((status == 0) ? true : status);
}