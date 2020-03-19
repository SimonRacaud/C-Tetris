/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T12:43:38+01:00 | Author: simon
*/

#include "tetris.h"

static size_t get_random_idx(size_t min, size_t max)
{
    return (rand() % (max - min + 1)) + min;
}

int set_next_piece(game_t *game)
{
    size_t idx = get_random_idx(0, (game->pieces.size - 1));

    if (idx >= (size_t)game->pieces.size) {
        my_putstr_error("Error: get random next piece : invalid idx\n");
        idx = 0;
    }
    if (game->pieces.pc[idx].mtx == NULL) {
        set_next_piece(game);
    } else {
        game->next_piece = dup_tetrimino(&game->pieces.pc[idx]);
        if (!game->next_piece)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
