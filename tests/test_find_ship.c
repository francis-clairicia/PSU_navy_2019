/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_find_ship.c
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(find_ship_by_pos, find_a_ship_in_a_navy_according_to_a_square_pos)
{
    char *positions[] = {
        "2:C1:C2",
        "3:D4:F4",
        "4:B5:B8",
        "5:D7:H7",
        NULL
    };
    navy_t *navy = create_navy(positions);
    ship_t *ship = NULL;
    int square_pos = 0;
    vector_t pos = {'F' - 'A', '7' - '1'};

    cr_assert_not_null(navy);
    ship = find_ship_by_pos(navy->ships, pos, &square_pos);
    cr_expect_not_null(ship);
    cr_expect_eq(ship->length, 5);
    cr_expect_eq(square_pos, 2, "Expected 2 but got %d", square_pos);
    destroy_navy(navy);
}

Test(find_ship_by_pos, return_null_when_not_find_ship)
{
    char *positions[] = {
        "2:C1:C2",
        "3:D4:F4",
        "4:B5:B8",
        "5:D7:H7",
        NULL
    };
    navy_t *navy = create_navy(positions);
    ship_t *ship = NULL;
    int square_pos = 0;
    vector_t pos = {'F' - 'A', '5' - '1'};

    cr_assert_not_null(navy);
    ship = find_ship_by_pos(navy->ships, pos, &square_pos);
    cr_expect_null(ship);
    destroy_navy(navy);
}