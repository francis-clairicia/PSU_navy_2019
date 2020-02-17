/*
** EPITECH PROJECT, 2019
** Header for libmy.a
** File description:
** Contains the prototypes of all functions in libmy.a
*/

#ifndef HEADER_MY_H
#define HEADER_MY_H

#include <stdbool.h>

int my_putchar(char c);
int my_put_nbr(long nb);
int my_putnbr_base(int nbr, char const *base);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_getnbr_base(char const *str, char const *base);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char **my_str_to_word_array(char const *str, char const *separators);
void my_free_word_array(char **array);
int my_array_len(char * const *array);
char **my_array_dup(char * const * src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isalphanum(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_strdup_char(char c);
char *my_nbr_to_str(int nb);
int my_nbr_len(long nb);
char const *my_strchr(char const *str, int c);
int my_strchr_index(char const *str, int c);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *convert_to_base(int nbr, char const *base);
char *open_file(char const *filepath, int (*error)(char const *));
int get_next_line(char **line, int fd);
char *join_path(char const *path_1, char const *path_2);
char *my_memset(char *buffer, char c, unsigned long size);
char *my_malloc(unsigned long size);

#endif
