/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_usleep.c
*/

#include <time.h>
#include "navy.h"

int my_usleep(int useconds)
{
    struct timespec time_pause = {0, MICRO_TO_NANO(useconds)};

    return (nanosleep(&time_pause, NULL));
}