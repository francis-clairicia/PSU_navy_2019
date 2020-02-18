/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** play_my_turn.c
*/

#include <unistd.h>
#include "navy.h"
#include "my.h"
#include "my_printf.h"

static bool wrong_input(void)
{
    my_putstr("wrong position\n");
    return (false);
}

static bool valid_input(char const *line, navy_t *enemy_navy)
{
    int x = 0;
    int y = 0;

    if (line == NULL)
        return (wrong_input());
    if (my_strlen(line) != 2)
        return (wrong_input());
    if (!my_strchr("ABCDEFGH", line[0]))
        return (wrong_input());
    if (!my_strchr("12345678", line[1]))
        return (wrong_input());
    x = line[0] - 'A';
    y = line[1] - '1';
    return (enemy_navy->map[y][x] == 0);
}

static vector_t get_coords(navy_t *enemy_navy)
{
    char *line = NULL;
    int x = 0;
    int y = 0;

    usleep(1000);
    do {
        my_putstr("attack: ");
        if (!get_next_line(&line, 0))
            return ((vector_t){-1, -1});
    } while (!valid_input(line, enemy_navy));
    x = line[0] - 'A';
    y = line[1] - '1';
    return ((vector_t){x, y});
}

int play_my_turn(pid_t player_pid, navy_t *enemy_navy)
{
    vector_t pos;
    int status = 0;

    if (enemy_navy == NULL)
        return (false);
    pos = get_coords(enemy_navy);
    if (!send_number(player_pid, pos.x, 32) || pos.x < 0)
        return (false);
    receive_bit(player_pid);
    usleep(100);
    if (!send_number(player_pid, pos.y, 32) || pos.y < 0)
        return (false);
    status = receive_number(player_pid, 2);
    hit_enemy_navy(enemy_navy, pos, (status > 0));
    return ((status == 0) ? true : status);
}