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
    clock_t my_clock = clock();
    clock_t elepse_time = clock();

    while (1) {
        display(tetris);
        while ((elepse_time - my_clock) / CLOCKS_PER_SEC < REFRESH_TIME)
            elepse_time = clock();
        my_clock = clock();
    }
    return tetris->exit_status;
}
