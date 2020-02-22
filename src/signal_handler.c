/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** signal.c
*/

#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include "navy.h"

static struct global_values GLOBAL = {0, 0};

bool send_bit(pid_t pid, bool bit)
{
    int signum = (bit == false) ? SIGUSR1 : SIGUSR2;

    return (kill(pid, signum) != -1);
}

bool receive_bit(pid_t pid)
{
    do
        pause();
    while (pid != ALL_PID && GLOBAL.sending_pid != pid);
    return (GLOBAL.bit_received);
}

void signal_user_handler(int signum, siginfo_t *infos,
    void *ucontext __attribute__((unused)))
{
    GLOBAL.sending_pid = infos->si_pid;
    if (signum == SIGUSR1)
        GLOBAL.bit_received = false;
    else
        GLOBAL.bit_received = true;
}

void bind_sigusr_signals(void)
{
    struct sigaction action;

    sigemptyset(&(action.sa_mask));
    action.sa_sigaction = &signal_user_handler;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
}