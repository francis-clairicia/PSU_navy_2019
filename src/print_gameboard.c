/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_gameboard.c
*/

#include "my.h"
#include "my_printf.h"
#include "navy.h"

static void set_square(char (*map)[16], vector_t pos, int value)
{
    if (pos.x < 0 || pos.y < 0)
        return;
    map[pos.y][2 * pos.x] = value;
}

static void set_ships(char (*map)[16], ship_t ships[4])
{
    int i = 0;
    int j = 0;
    vector_t pos;
    char value = '\0';

    for (i = 0; i < 4; i += 1) {
        for (j = 0; j < ships[i].length; j += 1) {
            pos = ships[i].squares[j].pos;
            value = ships[i].length + 48;
            set_square(map, pos, value);
        }
    }
}

static void set_strikes(char (*map)[16], int (*strikes)[8])
{
    int x = 0;
    int y = 0;

    while (y < 8) {
        if (strikes[y][x] == 1)
            map[y][2 * x] = 'o';
        else if (strikes[y][x] == 2)
            map[y][2 * x] = 'x';
        x += 1;
        if (x == 8) {
            x = 0;
            y += 1;
        }
    }
}

void print_gameboard(navy_t *navy)
{
    char map[8][16] = {
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . .",
        ". . . . . . . ."
    };
    int i = 0;

    if (navy == NULL)
        return;
    if (navy->ships != NULL)
        set_ships(map, navy->ships);
    set_strikes(map, navy->map);
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (i = 0; i < 8; i += 1)
        my_printf("%d|%s\n", i + 1, map[i]);
}