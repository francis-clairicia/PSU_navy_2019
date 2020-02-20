/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_errors.c
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(error_buffer, check_for_script_validity)
{
    char *navy_pos[] = {"2:C1:C2",
        "3:D4:F4",
        "4:B5:B8",
        "5:D7:H7",
        NULL
    };

    cr_assert_eq(error_buffer(navy_pos), false);
}

Test(error_buffer, put_error_for_invalid_characters)
{
    char *navy_pos_1[] = {"a:C1:C2", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};
    char *navy_pos_2[] = {"2:c1:D2", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};
    char *navy_pos_3[] = {"2:C1:C*", "3:D4:F4", "4:B5:B8", "5:D7:H7", NULL};

    cr_assert_eq(error_buffer(navy_pos_1), true);
    cr_assert_eq(error_buffer(navy_pos_2), true);
    cr_assert_eq(error_buffer(navy_pos_3), true);
}

Test(error_buffer, put_error_when_the_cases_do_not_match)
{
    char *navy_pos_1[] = {"2:C1:C4", "3:D4:F4", "4:B5:B8", "5:B1:F1", NULL};
    char *navy_pos_2[] = {"2:C1:D2", "3:D4:F4", "4:B5:B8", "5:B1:F1", NULL};
    char *navy_pos_3[] = {"2:C1:H2", "3:D4:F4", "4:B5:B8", "5:B1:F1", NULL};

    cr_assert_eq(error_buffer(navy_pos_1), true);
    cr_assert_eq(error_buffer(navy_pos_2), true);
    cr_assert_eq(error_buffer(navy_pos_3), true);
}

Test(error_buffer, put_error_when_the_ships_overflow)
{
    char *navy_pos[] = {"2:C1:C4",
        "3:D4:F4",
        "4:B5:B8",
        "5:B1:F1",
        NULL
    };

    cr_assert_eq(error_buffer(navy_pos), true);
}