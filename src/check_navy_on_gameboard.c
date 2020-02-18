/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_navy_on_gameboard.c
*/

#include <stdlib.h>
#include "navy.h"
#include "my.h"

static bool set_vertical_navy(int (*gb)[8], int length, int x, int y)
{
    int i = 0;
    int yi = 0;

    if (y + length > 8)
        return (false);
    for (i = 0; i < length; i += 1) {
        yi = y + i;
        if (gb[yi][x] != 0)
            return (false);
        gb[yi][x] = length;
    }
    return (true);
}

static bool set_horizontal_navy(int (*gb)[8], int length, int x, int y)
{
    int i = 0;
    int xi = 0;

    if (x + length > 8)
        return (false);
    for (i = 0; i < length; i += 1) {
        xi = x + i;
        if (gb[y][xi] != 0)
            return (false);
        gb[y][xi] = length;
    }
    return (true);
}

static bool set_navy(int (*gb)[8],
    char const *length_str, char const *first_pos, char const *last_pos)
{
    int length = my_getnbr(length_str);
    int x = first_pos[0] - 'A';
    int y = first_pos[1] - '1';

    if (first_pos[1] == last_pos[1]) {
        if (!set_horizontal_navy(gb, length, x, y))
            return (false);
    } else if (first_pos[0] == last_pos[0]) {
        if (!set_vertical_navy(gb, length, x, y))
            return (false);
    }
    return (true);
}

bool check_navy_on_gameboard(char * const *positions)
{
    int gb[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    int i = 0;
    char **pos = NULL;

    for (i = 0; positions[i] != NULL; i += 1) {
        pos = my_str_to_word_array(positions[i], ":");
        if (pos == NULL || !set_navy(gb, pos[0], pos[1], pos[2])) {
            my_free_word_array(pos);
            return (false);
        }
        my_free_word_array(pos);
    }
    return (true);
}