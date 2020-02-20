/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** errors.c
*/

#include <stddef.h>
#include "my.h"
#include "navy.h"

static bool free_array_and_return(char **array, bool status)
{
    my_free_word_array(array);
    return (status);
}

static bool error_cases(char const *length, char const *first, char const *last)
{
    int navy_length = my_getnbr(length) - 1;
    int row_distance = 0;
    int column_distance = 0;

    if (my_strlen(length) != 1 || !my_strchr("2345", length[0]))
        return (true);
    if (my_strlen(first) != 2 || !my_strchr("ABCDEFGH", first[0])
    || !my_strchr("12345678", first[1]))
        return (true);
    if (my_strlen(last) != 2 || !my_strchr("ABCDEFGH", last[0])
    || !my_strchr("12345678", first[1]))
        return (true);
    row_distance = last[0] - first[0];
    column_distance = last[1] - first[1];
    if (!((last[0] == first[0]) ^ (last[1] == first[1]))
    || row_distance < 0 || column_distance < 0)
        return (true);
    if (!((row_distance == navy_length) ^ (column_distance == navy_length)))
        return (true);
    return (false);
}

static bool error_line(char const *line, bool *navy)
{
    char **splitted_line = my_str_to_word_array(line, ":");
    int navy_id = 0;

    if (splitted_line == NULL)
        return (true);
    if (my_array_len(splitted_line) != 3)
        return (free_array_and_return(splitted_line, true));
    if (error_cases(splitted_line[0], splitted_line[1], splitted_line[2]))
        return (free_array_and_return(splitted_line, true));
    navy_id = my_getnbr(splitted_line[0]) - 2;
    if (navy[navy_id] == true)
        return (free_array_and_return(splitted_line, true));
    navy[navy_id] = true;
    return (free_array_and_return(splitted_line, false));
}

int error_buffer(char * const *buffer)
{
    int i = 0;
    bool navy_already_set[4] = {false, false, false, false};

    if (buffer == NULL)
        return (true);
    if (my_array_len(buffer) != 4)
        return (true);
    for (i = 0; buffer[i] != NULL; i += 1) {
        if (error_line(buffer[i], navy_already_set))
            return (true);
    }
    return (!check_navy_on_gameboard(buffer));
}