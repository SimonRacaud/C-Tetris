/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-18T10:36:20+01:00 | Author: simon
*/

#include "tetris.h"

extern const int REFRESH_TIME;

void set_game_speed(game_t *tetris)
{
    tetris->refresh_time = (REFRESH_TIME - (double)(tetris->level / 10));
}
