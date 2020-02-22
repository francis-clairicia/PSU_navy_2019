/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_recieve_number.c
*/

#include <time.h>
#include "navy.h"

bool send_number(pid_t pid, int number, int size)
{
    int i = 0;

    for (i = 0; i < size; i += 1) {
        if (!send_bit(pid, ((number & (1 << i)) != 0)))
            return (false);
        my_usleep(1000);
    }
    return (true);
}

int receive_number(pid_t pid, int size)
{
    int i = 0;
    int number = 0;

    for (i = 0; i < size; i += 1)
        number |= (receive_bit(pid) << i);
    my_usleep(1100);
    return (number);
}