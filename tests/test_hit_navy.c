/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_hit_navy.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(hit_my_navy, is_called_when_enemy_plays)
{
    char *navy_pos[] = {"2:C1:C2", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};
    navy_t *navy = create_navy(navy_pos);
    ship_t *ship_hitted = NULL;
    int square = 0;

    cr_redirect_stdout();
    cr_assert_not_null(navy);
    cr_assert_not_null(navy->ships);
    cr_expect_eq(hit_my_navy(navy, (vector_t){0, 0}), false);
    cr_expect_eq(navy->map[0][0], 1);
    cr_expect_eq(hit_my_navy(navy, (vector_t){2, 1}), true);
    ship_hitted = find_ship_by_pos(navy->ships, (vector_t){2, 1}, &square);
    cr_expect_not_null(ship_hitted);
    if (ship_hitted != NULL) {
        cr_expect_eq(ship_hitted->length, 2);
        cr_expect_eq(ship_hitted->squares[square].destroyed, true);
        cr_expect_eq(navy->map[1][2], 2);
    }
    cr_expect_stdout_eq_str("A1: missed\nC2: hit\n");
    destroy_navy(navy);
}

Test(hit_enemy_navy, is_called_when_player_plays)
{
    navy_t *navy = create_empty_navy();

    cr_redirect_stdout();
    hit_enemy_navy(navy, (vector_t){5, 1}, false);
    cr_expect_eq(navy->map[1][5], 1);
    hit_enemy_navy(navy, (vector_t){7, 2}, true);
    cr_expect_eq(navy->map[2][7], 2);
    destroy_navy(navy);
}