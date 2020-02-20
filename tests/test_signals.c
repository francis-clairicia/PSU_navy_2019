/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** test_signals.c
*/

#include <criterion/criterion.h>
#include <signal.h>
#include "navy.h"

Test(send_number_and_receive_number, send_informations_to_an_another_process)
{
    int parent_pid = getpid();
    int child_pid = fork();

    bind_sigusr_signals();
    if (child_pid == 0) {
        cr_assert_eq(send_number(parent_pid, -29, 32), true);
        cr_assert_eq(receive_number(parent_pid, 7), 55);
    } else {
        cr_assert_eq(receive_number(child_pid, 32), -29);
        cr_assert_eq(send_number(child_pid, 55, 7), true);
    }
}