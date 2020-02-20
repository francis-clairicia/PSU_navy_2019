/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** init.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include "navy.h"
#include "my.h"

navy_t *create_empty_navy(void)
{
    navy_t *navy = malloc(sizeof(navy_t));
    int i = 0;
    int j = 0;

    if (navy == NULL)
        return (NULL);
    navy->ships = NULL;
    for (i = 0; i < 8; i += 1) {
        for (j = 0; j < 8; j += 1)
            navy->map[j][i] = 0;
    }
    return (navy);
}

navy_t *create_navy(char * const *positions)
{
    navy_t *navy = create_empty_navy();

    if (navy == NULL)
        return (NULL);
    navy->ships = malloc(sizeof(ship_t) * 4);
    if (!init_ships(navy->ships, positions)) {
        destroy_navy(navy);
        return (NULL);
    }
    return (navy);
}

static void *stop_and_return(char *line, char **array, int fd, void *ptr)
{
    if (line != NULL)
        free(line);
    if (array != NULL)
        my_free_word_array(array);
    if (fd != -1)
        close(fd);
    return (ptr);
}

navy_t *create_navy_from_file(char const *filepath)
{
    char *line = NULL;
    char **positions = malloc(sizeof(char *) * 5);
    int fd = open(filepath, O_RDONLY);
    int i = 0;

    if (filepath == NULL || positions == NULL || fd < 0)
        return (stop_and_return(NULL, positions, fd, NULL));
    while (get_next_line(&line, fd) && i < 4) {
        positions[i] = my_strdup(line);
        i += 1;
    }
    positions[4] = NULL;
    if (my_array_len(positions) != 4 || error_buffer(positions))
        return (stop_and_return(line, positions, fd, NULL));
    return (stop_and_return(line, positions, fd, create_navy(positions)));
}