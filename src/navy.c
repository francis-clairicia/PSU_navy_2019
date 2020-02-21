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
        player_pid = receive_number(ALL_PID, 32);
        usleep(1100);
        send_bit(player_pid, true);
        my_putstr("\nenemy connected\n");
    } else {
        if (!send_number(player_pid, getpid(), 32))
            return (-1);
        receive_bit(player_pid);
        my_putstr("successfully connected\n");
    }
    return (player_pid);

}

int navy_game(pid_t player_pid, char const *filepath)
{
    navy_t *my_navy = create_navy_from_file(filepath);
    navy_t *enemy_navy = create_empty_navy();
    bool turn = (player_pid < 0) ? true : false;
    int output = 0;

    if (my_navy == NULL || enemy_navy == NULL) {
        destroy_navy(my_navy);
        destroy_navy(enemy_navy);
        return (84);
    }
    player_pid = etablish_connection(player_pid);
    if (player_pid < 0)
        return (84);
    my_putchar('\n');
    output = gameplay_navy(my_navy, enemy_navy, player_pid, turn);
    destroy_navy(my_navy);
    destroy_navy(enemy_navy);
    return (output);
}