/*
** EPITECH PROJECT, 2019
** mylist.h
** File description:
** Header for linked list functions
*/

#ifndef HEADER_MY_LIST
#define HEADER_MY_LIST

#include <stdlib.h>

typedef struct linked_list
{
    long data;
    struct linked_list *previous;
    struct linked_list *next;
} list_t;

list_t *my_list(int nb_element, ...);
int my_list_size(list_t *begin);
int my_put_in_list(list_t **list, long data);
int my_append_to_list(list_t **list, long data);
void my_concat_list(list_t **begin1, list_t *begin2);
void my_free_list(list_t **list, int free_ptr);
void my_rev_list(list_t *begin);
char *my_list_to_str(list_t *list);
char *my_concat_str_list(list_t *begin, char separator, int *len);
list_t *my_node(list_t *begin, int index);
void my_delete_node(list_t **list, int i, int free_ptr);

#endif
