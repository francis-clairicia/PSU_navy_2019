/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_recieve_number.c
*/

#include "navy.h"

int kill(pid_t pid, int sig);

bool send_number(pid_t pid, int number, int size)
{
    int i = 0;

    for (i = 0; i < size; i += 1) {
        if (!send_bit(pid, ((number & (1 << i)) != 0)))
            return (false);
        usleep(1000);
    }
    return (true);
}

int receive_number(pid_t pid, int size)
{
    int i = 0;
    int number = 0;

    for (i = 0; i < size; i += 1)
        number = number | (receive_bit(pid) << i);
    return (number);
}