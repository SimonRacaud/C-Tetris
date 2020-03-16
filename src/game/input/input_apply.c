/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T10:29:06+01:00 | Author: simon
*/

#include "tetris.h"

int input_apply(char *input, int size, game_t *tetris)
{
    if (my_strcmp(input, "\e") == 0) {
        tetris->status = FAIL;
    }
    return EXIT_SUCCESS;
}
