/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** destroy_navy.c
*/

#include <stdlib.h>
#include "navy.h"

void destroy_navy(navy_t *navy)
{
    int i = 0;

    if (navy == NULL)
        return;
    if (navy->ships != NULL) {
        for (i = 0; i < 4; i += 1)
            free(navy->ships[i].squares);
        free(navy->ships);
    }
    free(navy);
}