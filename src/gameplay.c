/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** gameplay.c
*/

#include "navy.h"
#include "my.h"
#include "my_printf.h"

static void print_gameplay(navy_t *my_navy, navy_t *enemy_navy)
{
    my_putstr("my positions:\n");
    print_gameboard(my_navy);
    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    print_gameboard(enemy_navy);
}

static int play(navy_t *my_navy, navy_t *enemy, pid_t player_pid, bool *turn)
{
    int i = 0;
    int (*turn_function)(pid_t, navy_t *) = NULL;
    navy_t *navy_struct = NULL;
    int status = 0;

    my_putchar('\n');
    for (i = 0; i < 2; i += 1) {
        turn_function = (*turn == true) ? play_my_turn : wait_enemy_turn;
        navy_struct = (*turn == true) ? enemy : my_navy;
        status = turn_function(player_pid, navy_struct);
        if (status == false)
            return (false);
        my_putchar('\n');
        if (status == 2)
            return (2);
        *turn = !(*turn);
    }
    my_putchar('\n');
    return (true);
}

int gameplay_navy(navy_t *my_navy, navy_t *enemy_navy,
    pid_t player_pid, bool turn)
{
    bool loop = true;
    int gameplay_status = 0;
    char *winner[2] = {"Enemy won", "I won"};

    print_gameplay(my_navy, enemy_navy);
    while (loop) {
        gameplay_status = play(my_navy, enemy_navy, player_pid, &turn);
        if (gameplay_status == false)
            return (0);
        print_gameplay(my_navy, enemy_navy);
        loop = (gameplay_status == true);
    }
    my_printf("%s\n", winner[turn]);
    return (!turn);
}