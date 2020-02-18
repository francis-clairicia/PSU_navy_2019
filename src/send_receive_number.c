/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** send_recieve_number.c
*/

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include "navy.h"

int kill(pid_t pid, int sig);

void send_number(pid_t pid, int number, int size)
{
    long mask = 1;
    bool bit;
    int i = 0;

    for (i = 0; i < size; i += 1) {
        bit = ((number & mask) != 0);
        send_bit(pid, bit);
        usleep(100);
        mask = mask << 1;
    }
}

int receive_number(pid_t pid, int size)
{
    int i = 0;
    int number = 0;
    int mask = 0;

    for (i = 0; i < size; i += 1) {
        mask = receive_bit(pid) << i;
        number = number | mask;
        mask = 0;
    }
    return (number);
}