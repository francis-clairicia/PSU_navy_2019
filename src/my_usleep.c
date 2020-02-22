/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_usleep.c
*/

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif

#include <time.h>

#define MICRO_TO_NANO(usec) (usec * 1000)

int my_usleep(int useconds)
{
    struct timespec time_pause = {0, MICRO_TO_NANO(useconds)};

    return (nanosleep(&time_pause, NULL));
}