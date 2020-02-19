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

static bool match_square(ship_t *ship, vector_t pos, int *square_index)
{
    int i = 0;
    bool match = false;

    for (i = 0; i < ship->length; i += 1) {
        if (compare_vectors(ship->squares[i].pos, pos) == true) {
            match = true;
            break;
        }
    }
    if (square_index != NULL && i < ship->length)
        *square_index = i;
    return (match);
}

ship_t *find_ship_by_pos(ship_t ships[4], vector_t pos, int *square_index)
{
    int i = 0;

    for (i = 0; i < 4; i += 1) {
        if (match_square(&ships[i], pos, square_index))
            return (&ships[i]);
    }
    return (NULL);
}