/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_print_gameboard.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(print_gameboard, print_the_navy_map)
{
    char *navy_pos[] = {"2:C1:C2", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};
    navy_t *navy = create_navy(navy_pos);

    cr_redirect_stdout();
    cr_assert_not_null(navy);
    cr_assert_not_null(navy->ships);
    cr_expect_eq(hit_my_navy(navy, (vector_t){0, 0}), false);
    cr_expect_eq(navy->map[0][0], 1);
    cr_expect_eq(hit_my_navy(navy, (vector_t){2, 1}), true);
    cr_expect_eq(navy->map[1][2], 2);
    print_gameboard(navy);
    cr_expect_stdout_eq_str("A1: missed\nC2: hit\n"
        " |A B C D E F G H\n"
        "-+---------------\n"
        "1|o . 2 . . . . .\n"
        "2|. . x . . . . .\n"
        "3|. . . . . . . .\n"
        "4|. . . 3 3 3 . .\n"
        "5|. 4 . . . . . .\n"
        "6|. 4 . . . . . .\n"
        "7|. 4 . 5 5 5 5 5\n"
        "8|. 4 . . . . . .\n");
    destroy_navy(navy);
}

Test(print_gameboard, print_an_empty_map)
{
    navy_t *navy = create_empty_navy();

    cr_redirect_stdout();
    cr_assert_not_null(navy);
    cr_expect_null(navy->ships);
    print_gameboard(navy);
    cr_expect_stdout_eq_str(
        " |A B C D E F G H\n"
        "-+---------------\n"
        "1|. . . . . . . .\n"
        "2|. . . . . . . .\n"
        "3|. . . . . . . .\n"
        "4|. . . . . . . .\n"
        "5|. . . . . . . .\n"
        "6|. . . . . . . .\n"
        "7|. . . . . . . .\n"
        "8|. . . . . . . .\n"
    );
    destroy_navy(navy);
}