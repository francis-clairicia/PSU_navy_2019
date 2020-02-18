/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#ifndef HEADER_NAVY
#define HEADER_NAVY

#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct vector
{
    int x;
    int y;
} vector_t;

typedef struct square
{
    vector_t pos;
    bool destroyed;
} square_t;

typedef struct ship
{
    int length;
    square_t *squares;
    bool destroyed;
} ship_t;

#define ALL_PID -1

int navy(pid_t player_pid, char * const *positions);
int error_buffer(char const *buffer);
bool check_navy_on_gameboard(char * const *positions);
bool init_ships(ship_t ships[4], char * const * positions);
void destroy_ships(ship_t ships[4]);
void print_gameboard(ship_t ships[4]);

void bind_sigusr_signals(void);
bool send_bit(pid_t pid, bool bit);
void send_number(pid_t pid, int number, int size);
bool receive_bit(pid_t pid);
int receive_number(pid_t pid, int size);
void signal_user_handler(int signum);

#endif