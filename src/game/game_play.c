/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T16:24:50+01:00 | Author: simon
*/

#include "tetris.h"

int game_play(game_t *tetris)
{
    while (1) {
        display(tetris);
    }
    return tetris->exit_status;
}
