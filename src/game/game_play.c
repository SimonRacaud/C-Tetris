/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T16:24:50+01:00 | Author: simon
*/

#include "tetris.h"

extern int REFRESH_TIME;
void my_colision(game_t *tetris);
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
            my_colision(tetris);
            tetris->ppiece.coord.y++;
            // TODO : eval piece (if it touch another piece in the map)
            time_display = clock();
        }
    }
    return EXIT_SUCCESS;
}

int game_play(game_t *tetris)
{
    while (tetris->status == RUNNING) {
        // set_cuurent_piece : set next piece as current piece (player_piece_t)
        // set_next_piece : Get new randow next piece
        if (piece_falling_loop(tetris) == EXIT_ERROR)
            return EXIT_ERROR;
        map_eval(tetris);
    }
    return tetris->exit_status;
}
