/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** init.c
*/

#include <stdlib.h>
#include "navy.h"

navy_t *create_navy(char * const *positions)
{
    navy_t *navy = malloc(sizeof(navy_t));
    int i = 0;
    int j = 0;

    if (navy == NULL)
        return (NULL);
    for (i = 0; i < 8; i += 1) {
        for (j = 0; j < 8; j += 1)
            navy->map[j][i] = 0;
    }
    if (!init_ships(navy->ships, positions)) {
        destroy_navy(navy);
        return (NULL);
    }
    return (navy);
}

void destroy_navy(navy_t *navy)
{
    int i = 0;

    if (navy == NULL)
        return;
    for (i = 0; i < 4; i += 1)
        free(navy->ships[i].squares);
    free(navy);
}