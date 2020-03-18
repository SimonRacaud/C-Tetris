/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T10:29:06+01:00 | Author: simon
*/

#include "tetris.h"

static int move_left(game_t *tetris)
{
    if (tetris->ppiece.coord.x > 0)
        tetris->ppiece.coord.x -= 1;
    return EXIT_SUCCESS;
}

static int move_right(game_t *tetris)
{
    if (tetris->ppiece.coord.x < tetris->conf.map_width)
        tetris->ppiece.coord.x += 1;
    return EXIT_SUCCESS;
}

int input_apply(char *input, int size, game_t *tetris)
{
    if (my_strcmp(input, "\e") == 0) {
        tetris->status = END;
    }
    if (my_strncmp(input, tetris->conf.key[LEFT_KEY], size) == 0)
        move_left(tetris);
    if (my_strncmp(input, tetris->conf.key[RIGHT_KEY], size) == 0)
        move_right(tetris);
    if (my_strncmp(input, tetris->conf.key[TURN_KEY], size) == 0)
        rotate(tetris->ppiece.piece);
    if (my_strncmp(input, tetris->conf.key[DROP_KEY], size) == 0)
        drop_piece(tetris);
    if (my_strncmp(input, tetris->conf.key[QUIT_KEY], size) == 0)
        return EXIT_ERROR;
    if (my_strncmp(input, tetris->conf.key[PAUSE_KEY], size) == 0)
        my_pause();
    return EXIT_SUCCESS;
}