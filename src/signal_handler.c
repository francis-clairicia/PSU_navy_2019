/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** signal.c
*/

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199506L
#endif

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

struct global_values
{
    pid_t sending_pid;
    int bit_received;
};

static struct global_values GLOBAL = {-1, false};

bool send_bit(pid_t pid, bool bit)
{
    int signum = (bit == true) ? SIGUSR2 : SIGUSR1;

    return (kill(pid, signum) != -1);
}

bool receive_bit(pid_t pid)
{
    bool loop = true;

    GLOBAL.sending_pid = pid;
    while (loop) {
        pause();
        loop = (GLOBAL.bit_received < 0);
    }
    return (GLOBAL.bit_received);
}

void signal_user_handler(int signum, siginfo_t *infos, void *ucontext)
{
    (void)ucontext;
    if (GLOBAL.sending_pid >= 0 && infos->si_pid != GLOBAL.sending_pid) {
        GLOBAL.bit_received = -1;
    } else {
        if (signum == SIGUSR1)
            GLOBAL.bit_received = false;
        else
            GLOBAL.bit_received = true;
    }
}

void bind_sigusr_signals(void)
{
    struct sigaction action;

    sigemptyset(&(action.sa_mask));
    action.sa_sigaction = signal_user_handler;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
}