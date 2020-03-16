/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T16:24:50+01:00 | Author: simon
*/

#include "tetris.h"

extern int REFRESH_TIME;

static int piece_falling_loop(game_t *tetris)
{
    clock_t time_display = clock();
    clock_t now;

    while (tetris->status == RUNNING && tetris->ppiece.is_fall) {
        if (catch_input(tetris) == EXIT_ERROR)
            return EXIT_ERROR;
        now = clock();
        if (((now - time_display) / CLOCKS_PER_SEC) >= REFRESH_TIME) {
            display(tetris);
            // TODO : move piece (down)
            // TODO : eval piece (if it touch another piece in the map)
            time_display = clock();
        }
    }
    return EXIT_SUCCESS;
}

int game_play(game_t *tetris)
{
    while (tetris->status == RUNNING) {
        set_player_piece(tetris->next_piece, &tetris->ppiece, tetris);
        set_next_piece(tetris);
        if (piece_falling_loop(tetris) == EXIT_ERROR)
            return EXIT_ERROR;
        map_eval(tetris);
    }
    return tetris->exit_status;
}
