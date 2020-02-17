/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** open_file.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *open_file(char const *filepath, int (*error)(char const *))
{
    int fd = open(filepath, O_RDONLY);
    struct stat statbuf;
    char *buffer;
    int size;

    if (fstat(fd, &statbuf) == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (statbuf.st_size + 1));
    if (buffer != NULL) {
        size = read(fd, buffer, statbuf.st_size);
        buffer[size] = '\0';
    }
    close(fd);
    if (error(buffer)) {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}