/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-18T10:23:50+01:00 | Author: simon
*/

#include "tetris.h"

void increase_line(game_t *tetris)
{
    tetris->line++;
    if ((tetris->line % 10) == 0 && tetris->line != 0) {
        increase_level(tetris);
    }
}
