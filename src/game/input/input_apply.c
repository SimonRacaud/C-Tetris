/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T10:29:06+01:00 | Author: simon
*/

#include "tetris.h"

static void move_left(game_t *tetris)
{
    if (tetris->ppiece.coord.x - 1 > 0)
        tetris->ppiece.coord.x -= 1;
    if (piece_have_collision(tetris))
        tetris->ppiece.coord.x += 1;
}

static void move_right(game_t *game)
{
    if (game->ppiece.coord.x + game->ppiece.piece->width < game->conf.map_width)
        game->ppiece.coord.x += 1;
    if (piece_have_collision(game))
        game->ppiece.coord.x -= 1;
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
        rotate(tetris);
    if (my_strncmp(input, tetris->conf.key[DROP_KEY], size) == 0)
        drop_piece(tetris);
    if (my_strncmp(input, tetris->conf.key[QUIT_KEY], size) == 0)
        return EXIT_ERROR;
    if (my_strncmp(input, tetris->conf.key[PAUSE_KEY], size) == 0)
        my_pause();
    return EXIT_SUCCESS;
}