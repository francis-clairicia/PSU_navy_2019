/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** hit_navy.c
*/

#include "navy.h"
#include "my.h"
#include "my_printf.h"

static void check_for_destroyed_ship(ship_t *ship)
{
    int i = 0;

    if (ship->destroyed)
        return;
    for (i = 0; i < ship->length; i += 1) {
        if (ship->squares[i].destroyed == false)
            return;
    }
    ship->destroyed = true;
}

static void print_hit_result(vector_t pos, bool hit)
{
    char *status[2] = {"missed", "hit"};

    my_printf("%c%c: %s\n", pos.x + 'A', pos.y + '1', status[hit]);
}

bool hit_my_navy(navy_t *navy, vector_t pos)
{
    int square_index = 0;
    ship_t *ship = NULL;
    bool hit = false;

    if (navy == NULL)
        return (false);
    ship = find_ship_by_pos(navy->ships, pos, &square_index);
    if (ship != NULL) {
        ship->squares[square_index].destroyed = true;
        check_for_destroyed_ship(ship);
        hit = true;
    }
    navy->map[pos.y][pos.x] = 1 + hit;
    print_hit_result(pos, hit);
    return (hit);
}

void hit_enemy_navy(navy_t *navy, vector_t pos, bool hit)
{
    navy->map[pos.y][pos.x] = 1 + hit;
    print_hit_result(pos, hit);
}