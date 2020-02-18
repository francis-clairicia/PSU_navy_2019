/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include <unistd.h>
#include "navy.h"
#include "my.h"
#include "my_printf.h"

static int etablish_connection(int player_pid)
{
    bind_sigusr_signals();
    my_printf("my_pid: %d\n", getpid());
    if (player_pid < 0) {
        my_putstr("waiting for enemy connection...\n");
        player_pid = receive_number(ALL_PID, 16);
        usleep(100);
        send_number(player_pid, 1, 1);
        my_putstr("\nenemy connected\n");
    } else {
        send_number(player_pid, getpid(), 16);
        receive_bit(player_pid);
        my_putstr("successfully connected\n");
    }
    return (player_pid);

}

int navy(pid_t player_pid, char * const *positions)
{
    ship_t my_ships[4];
    ship_t enemy_ships[4];

    if (!init_ships(my_ships, positions) || !init_ships(enemy_ships, NULL))
        return (84);
    player_pid = etablish_connection(player_pid);
    my_putchar('\n');
    gameplay_navy(my_ships, enemy_ships);
    destroy_ships(my_ships);
    destroy_ships(enemy_ships);
    return (0);
}