/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_all_navy_destroyed.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

static void destroy_all_the_navy(navy_t *navy)
{
    int i = 0;
    int j = 0;
    ship_t *ship = NULL;

    if (navy == NULL || navy->ships == NULL)
        return;
    for (i = 0; i < 4; i += 1) {
        ship = &(navy->ships[i]);
        for (j = 0; j < ship->length; j += 1)
            hit_my_navy(navy, ship->squares[j].pos);
    }
}

Test(all_navy_destroyed, check_if_the_game_is_finished)
{
    char *navy_pos[] = {"2:C1:C2", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};
    navy_t *navy = create_navy(navy_pos);

    cr_redirect_stdout();
    cr_assert_not_null(navy);
    cr_assert_not_null(navy->ships);
    cr_expect_eq(all_navy_destroyed(navy), false);
    destroy_all_the_navy(navy);
    cr_expect_eq(all_navy_destroyed(navy), true);
    destroy_navy(navy);
}