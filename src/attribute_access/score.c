/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-18T10:23:50+01:00 | Author: simon
*/

#include "tetris.h"

void increase_score(game_t *tetris, int coef)
{
    tetris->score += coef;
}

void update_high_score(game_t *tetris)
{
    if (tetris->score > tetris->high_score) {
        tetris->high_score = tetris->score;
    }
}
