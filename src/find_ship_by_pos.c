/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** find_ship_by_pos.c
*/

#include "navy.h"

static bool compare_vectors(vector_t v1, vector_t v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

static bool match_square(ship_t *ship, vector_t pos)
{
    int i = 0;

    for (i = 0; i < ship->length; i += 1) {
        if (compare_vectors(ship->squares[i].pos, pos) == true)
            return (true);
    }
    return (false);
}

ship_t *find_ship_by_pos(ship_t ships[4], vector_t pos, int *square_index)
{
    int i = 0;

    while (i < 4) {
        if (match_square(&ships[i], pos)) {
            return (&ships[i]);
        }
        i += 1;
    }
    if (square_index != NULL)
        *square_index = i;
    return ((i < 4) ? &ships[i] : NULL);
}