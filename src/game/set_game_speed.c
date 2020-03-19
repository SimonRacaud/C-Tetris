/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-18T10:36:20+01:00 | Author: simon
*/

#include "tetris.h"

extern const float REFRESH_TIME;
extern const float FPS;
extern const float MIN_REFRESH_TIME;

void set_game_speed(game_t *tetris)
{
    double sub = ((double)tetris->level / 10) - 0.1;
    double init_time = REFRESH_TIME;

    tetris->refresh_time = (init_time - sub);
    if (tetris->refresh_time <= MIN_REFRESH_TIME)
        tetris->refresh_time = MIN_REFRESH_TIME;
}
