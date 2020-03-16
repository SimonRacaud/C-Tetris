/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T16:24:50+01:00 | Author: simon
*/

#include "tetris.h"

extern int REFRESH_TIME;

int game_play(game_t *tetris)
{
    clock_t time_display = clock();
    clock_t now;

    while (tetris->status == RUNNING) {
        if (catch_input(tetris) == EXIT_ERROR)
            return EXIT_ERROR;
        now = clock();
        if (((now - time_display) / CLOCKS_PER_SEC) >= REFRESH_TIME) {
            display(tetris);
            time_display = clock();
        }
    }
    return tetris->exit_status;
}
