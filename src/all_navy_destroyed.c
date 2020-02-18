/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** all_navy_destroyed.c
*/

#include "navy.h"

bool all_navy_destroyed(navy_t *navy)
{
    int i = 0;

    for (i = 0; i < 4; i += 1) {
        if (navy->ships[i].destroyed == false)
            return (false);
    }
    return (true);
}