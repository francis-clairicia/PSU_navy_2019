/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_gameboard.c
*/

#include "my.h"
#include "my_printf.h"
#include "navy.h"

static void set_ships(char (*map)[9], ship_t ships[4])
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    char value = '\0';

    for (i = 0; i < 4; i += 1) {
        for (j = 0; j < ships[i].length; j += 1) {
            x = ships[i].squares[j].pos.x;
            y = ships[i].squares[j].pos.y;
            value = ships[i].length + 48;
            map[y][x] = (ships[i].squares[j].destroyed) ? 'x' : value;
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

void print_gameboard(ship_t ships[4])
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

    set_ships(map, ships);
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (i = 0; i < 8; i += 1)
        print_line(i + 1, map[i]);
}