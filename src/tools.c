/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T09:23:55+01:00 | Author: simon
*/

#include "tetris.h"

bool have_str_in_array(char **array, int size, const char *str)
{
    for (int i = 0; i < size; i++) {
        if (my_strcmp(array[i], str) == 0) {
            return true;
        }
    }
    return false;
}
