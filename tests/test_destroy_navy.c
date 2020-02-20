/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_destroy_navy.c
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(destroy_navy, test_not_crash_for_null_value)
{
    destroy_navy(NULL);
    cr_assert(true);
}