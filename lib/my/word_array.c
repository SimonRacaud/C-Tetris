/*
** EPITECH PROJECT, 2019
** Lib My - 04/03/2002
** File description:
** Word array utility tools
*/

#include "my.h"

int word_array_len(char **array)
{
    int len = 0;

    for (int i = 0; array[i] != NULL; i++)
        len++;
    return len;
}

void word_array_destroy(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
