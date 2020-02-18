/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** destroy_ships.c
*/

#include <stdlib.h>
#include "navy.h"

void destroy_ships(ship_t ships[4])
{
    int i = 0;

    for (i = 0; i < 4; i += 1)
        free(ships[i].squares);
}