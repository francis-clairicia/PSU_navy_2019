/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_create_navy.c
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "navy.h"
#include "my.h"
#include "my_printf.h"

Test(create_empty_navy, will_initialize_a_navy)
{
    navy_t *navy = create_empty_navy();
    int x = 0;
    int y = 0;

    cr_assert_not_null(navy);
    cr_expect_null(navy->ships);
    for (y = 0; y < 8; y += 1) {
        for (x = 0; x < 8; x += 1)
            cr_expect_eq(navy->map[y][x], 0);
    }
    destroy_navy(navy);
}

static bool x_ship_test(ship_t *ships, int index,
    int length, vector_t first_pos)
{
    vector_t pos;
    int i = 0;
    bool status = true;

    if (ships == NULL || ships[index].length != length) {
        my_printf("Expected %d but got %d\n", length, ships[index].length);
        return (false);
    }
    if (ships[index].squares == NULL)
        return (false);
    for (i = 0; i < length; i += 1) {
        pos = ships[index].squares[i].pos;
        if (pos.x != first_pos.x + i || pos.y != first_pos.y) {
            my_printf("Expected (%d, %d) ", first_pos.x + i, first_pos.y);
            my_printf("but got (%d, %d)\n", pos.x, pos.y);
            status = false;
        }
    }
    return (status);
}

static bool y_ship_test(ship_t *ships, int index,
    int length, vector_t first_pos)
{
    vector_t pos;
    int i = 0;
    bool status = true;

    if (ships == NULL || ships[index].length != length) {
        my_printf("Expected %d but got %d\n", length, ships[index].length);
        return (false);
    }
    if (ships[index].squares == NULL)
        return (false);
    for (i = 0; i < length; i += 1) {
        pos = ships[index].squares[i].pos;
        if (pos.x != first_pos.x || pos.y != first_pos.y + i) {
            my_printf("Expected (%d, %d) ", first_pos.x, first_pos.y + i);
            my_printf("but got (%d, %d)\n", pos.x, pos.y);
            status = false;
        }
    }
    return (status);
}

Test(create_navy, create_a_navy_according_to_given_poistions)
{
    char *navy_pos[] = {
        "2:C1:C2",
        "3:D4:F4",
        "4:B5:B8",
        "5:D7:H7",
        NULL
    };
    navy_t *navy = create_navy(navy_pos);

    cr_assert_not_null(navy);
    cr_assert_not_null(navy->ships);
    cr_expect_eq(y_ship_test(navy->ships, 0, 2, (vector_t){2, 0}), true);
    cr_expect_eq(x_ship_test(navy->ships, 1, 3, (vector_t){3, 3}), true);
    cr_expect_eq(y_ship_test(navy->ships, 2, 4, (vector_t){1, 4}), true);
    cr_expect_eq(x_ship_test(navy->ships, 3, 5, (vector_t){3, 6}), true);
    destroy_navy(navy);
}

Test(create_navy_from_file, create_a_navy_according_to_a_file_config)
{
    char navy_pos[] = "2:C1:C2\n"
        "3:D4:F4\n"
        "4:B5:B8\n"
        "5:D7:H7\n";
    char test_filepath[] = "tests/map.txt";
    FILE *test = fopen(test_filepath, "w");
    navy_t *navy = NULL;

    fwrite(navy_pos, sizeof(char), my_strlen(navy_pos), test);
    fclose(test);
    navy = create_navy_from_file(test_filepath);
    cr_assert_not_null(navy);
    cr_assert_not_null(navy->ships);
    cr_expect_eq(y_ship_test(navy->ships, 0, 2, (vector_t){2, 0}), true);
    cr_expect_eq(x_ship_test(navy->ships, 1, 3, (vector_t){3, 3}), true);
    cr_expect_eq(y_ship_test(navy->ships, 2, 4, (vector_t){1, 4}), true);
    cr_expect_eq(x_ship_test(navy->ships, 3, 5, (vector_t){3, 6}), true);
    destroy_navy(navy);
    remove(test_filepath);
}