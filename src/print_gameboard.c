/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_gameboard.c
*/

#include "my.h"
#include "my_printf.h"
#include "navy.h"

static void set_square(char (*map)[9], vector_t pos, int value)
{
    if (pos.x < 0 || pos.y < 0)
        return;
    map[pos.y][pos.x] = value;
}

static void set_ships(char (*map)[9], ship_t ships[4])
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

static void set_strikes(char (*map)[9], int (*strikes)[8])
{
    int x = 0;
    int y = 0;

    while (y < 8) {
        if (strikes[y][x] == 1)
            map[y][x] = 'o';
        else if (strikes[y][x] == 2)
            map[y][x] = 'x';
        x += 1;
        if (x == 8) {
            x = 0;
            y += 1;
        }
    }
}

static void print_line(int line_nb, char const *line)
{
    int i = 0;

    my_printf("%d|", line_nb);
    for (i = 0; line[i] != '\0'; i += 1) {
        my_putchar(line[i]);
        if (line[i + 1] != '\0')
            my_putchar(' ');
    }
    my_putchar('\n');
}

void print_gameboard(navy_t *navy)
{
    char map[8][9] = {
        "........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........",
        "........"
    };
    int i = 0;

    if (navy == NULL)
        return;
    set_ships(map, navy->ships);
    set_strikes(map, navy->map);
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (i = 0; i < 8; i += 1)
        print_line(i + 1, map[i]);
}