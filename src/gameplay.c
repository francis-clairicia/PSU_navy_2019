/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** gameplay.c
*/

#include "navy.h"
#include "my.h"

int gameplay_navy(ship_t my_ships[4], ship_t enemy_ships[4])
{
    my_putstr("my positions:\n");
    print_gameboard(my_ships);
    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    print_gameboard(enemy_ships);
    return (0);
}