/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** play_my_turn.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "navy.h"
#include "my.h"

static bool wrong_input(void)
{
    my_putstr("wrong position\n");
    return (false);
}

static bool valid_input(char const *line, navy_t *enemy_navy)
{
    int x = 0;
    int y = 0;

    if (line == NULL || my_strlen(line) != 2)
        return (wrong_input());
    if (!my_strchr("ABCDEFGH", line[0]) || !my_strchr("12345678", line[1]))
        return (wrong_input());
    x = line[0] - 'A';
    y = line[1] - '1';
    if (enemy_navy->map[y][x] != 0)
        return (wrong_input());
    return (true);
}

static vector_t get_coords(navy_t *enemy_navy)
{
    char *line = NULL;
    int x = 0;
    int y = 0;

    usleep(5000);
    do {
        my_putstr("attack: ");
        if (!get_next_line(&line, 0))
            return ((vector_t){-1, -1});
    } while (!valid_input(line, enemy_navy));
    x = line[0] - 'A';
    y = line[1] - '1';
    free(line);
    return ((vector_t){x, y});
}

int play_my_turn(pid_t player_pid, navy_t *enemy_navy)
{
    vector_t pos;
    int square = 0;
    int status = 0;

    if (enemy_navy == NULL)
        return (false);
    pos = get_coords(enemy_navy);
    if (pos.x < 0 || pos.y < 0)
        square = (1 << 6);
    else
        square = (pos.x << 3) | pos.y;
    if (!send_number(player_pid, square, 7) || square == (1 << 6))
        return (false);
    status = receive_number(player_pid, 2);
    hit_enemy_navy(enemy_navy, pos, (status > 0));
    return ((status == 2) ? 2 : true);
}