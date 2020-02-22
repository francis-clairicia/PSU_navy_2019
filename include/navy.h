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

struct global_values
{
    pid_t sending_pid;
    bool bit_received;
};

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

typedef struct navy
{
    int map[8][8];
    ship_t *ships;
} navy_t;

#define ALL_PID -1
#define MICRO_TO_NANO(usec) (usec * 1000)

int navy_game(pid_t player_pid, char const *filepath);
int error_buffer(char * const *buffer);
bool check_navy_on_gameboard(char * const *positions);
void print_gameboard(navy_t *navy);
int gameplay_navy(navy_t *my_navy, navy_t *enemy_navy,
    pid_t player_pid, bool turn);

navy_t *create_empty_navy(void);
navy_t *create_navy(char * const *positions);
navy_t *create_navy_from_file(char const *filepath);
void destroy_navy(navy_t *navy);
bool init_ships(ship_t *ships, char * const * positions);
ship_t *find_ship_by_pos(ship_t *ships, vector_t pos, int *square_index);
bool hit_my_navy(navy_t *navy, vector_t pos);
void hit_enemy_navy(navy_t *navy, vector_t pos, bool hit);

int play_my_turn(pid_t player_pid, navy_t *enemy_navy);
int wait_enemy_turn(pid_t player_pid, navy_t *my_navy);
bool all_navy_destroyed(navy_t *navy);

void bind_sigusr_signals(void);
bool send_bit(pid_t pid, bool bit);
bool send_number(pid_t pid, int number, int size);
bool receive_bit(pid_t pid);
int receive_number(pid_t pid, int size);
int my_usleep(int useconds);

#endif