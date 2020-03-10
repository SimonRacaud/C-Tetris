/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T17:44:40+01:00 | Author: simon
*/

#include "tetris.h"

static file_list_t *file_list_create_node(const char *filename)
{
    file_list_t *node = NULL;

    node = malloc(sizeof(file_list_t));
    if (!node)
        return NULL;
    node->next = NULL;
    node->filename = my_strdup(filename);
    return node;
}

int file_list_add(file_list_t **list, const char *filename)
{
    file_list_t *ptr = *list;

    if (!(*list)) {
        (*list) = file_list_create_node(filename);
        if (!(*list))
            return EXIT_FAILURE;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = file_list_create_node(filename);
        if (!ptr->next) {
            my_putstr_error("linked_file_list : error\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void file_list_destroy(file_list_t *list)
{
    file_list_t *next_ptr = NULL;
    file_list_t *ptr = list;

    if (!list) {
        return;
    } else {
        do {
            next_ptr = ptr->next;
            free(ptr->filename);
            free(ptr);
            ptr = next_ptr;
        } while (next_ptr);
    }
}
