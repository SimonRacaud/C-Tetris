/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-18T10:23:50+01:00 | Author: simon
*/

#include "tetris.h"

void increase_level(game_t *tetris)
{
    tetris->level++;
    set_game_speed(tetris);
}
