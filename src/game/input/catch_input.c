/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T08:43:42+01:00 | Author: simon
*/

#include "tetris.h"

int catch_input(game_t *tetris)
{
    char in[4];
    int size = 4;
    bool have_input = get_input(in, size);

    if (!have_input)
        return EXIT_SUCCESS;
    if (input_apply(in, size, tetris) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
