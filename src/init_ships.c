/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** init_ships.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "navy.h"
#include "my.h"

static void init_square_buffer(ship_t *ship)
{
    int i = 0;

    for (i = 0; i < ship->length; i += 1) {
        ship->squares[i].pos = (vector_t){-1, -1};
        ship->squares[i].destroyed = false;
    }
}

static void set_ship(ship_t *ship, char const *first, char const *last)
{
    int i = 0;
    bool vertical = (first[0] == last[0]);
    int x = first[0] - 'A';
    int y = first[1] - '1';
    int xi = x;
    int yi = y;

    for (i = 0; i < ship->length; i += 1) {
        if (vertical)
            yi = y + i;
        else
            xi = x + i;
        ship->squares[i].pos = (vector_t){xi, yi};
        ship->squares[i].destroyed = false;
    }
}

static bool init_ship(ship_t *ship, int i, char const *position)
{
    char **infos = my_str_to_word_array(position, ":");

    ship->length = (infos != NULL) ? my_getnbr(infos[0]) : i + 2;
    ship->destroyed = false;
    ship->squares = malloc(sizeof(square_t) * ship->length);
    if (ship->squares == NULL) {
        my_free_word_array(infos);
        return (false);
    }
    if (infos != NULL)
        set_ship(ship, infos[1], infos[2]);
    else
        init_square_buffer(ship);
    my_free_word_array(infos);
    return (true);
}

bool init_ships(ship_t ships[4], char * const * positions)
{
    int i = 0;

    for (i = 0; i < 4; i += 1)
        init_ship(&ships[i], i, (positions != NULL) ? positions[i] : NULL);
    return (true);
}