/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T21:04:36+01:00 | Author: simon
*/

#include "tetris.h"

static bool piece_move_vertical(game_t *tetris, int shift)
{
    for (ssize_t i = 0; i < tetris->ppiece.speed_y; i++) {
        tetris->ppiece.coord.y += shift;
        if (piece_have_collision(tetris)) {
            tetris->ppiece.coord.y -= shift;
            tetris->ppiece.is_fall = false;
            return false;
        } else if (!tetris->ppiece.is_fall) {
            tetris->ppiece.is_fall = true;
        }
    }
    return true;
}

static bool piece_move_horizontal(game_t *tetris, enum piece_move_sens sens)
{
    int shift = 0;

    if (sens == PIECE_SENS_V_LEFT) {
        shift = -1;
    } else if (sens == PIECE_SENS_V_RIGHT) {
        shift = 1;
    } else {
        return false;
    }
    tetris->ppiece.coord.x += shift;
    if (piece_have_collision(tetris)) {
        tetris->ppiece.coord.y -= shift;
        return false;
    }
    return true;
}

bool piece_move(game_t *tetris, enum piece_move_sens sens)
{
    if (sens == PIECE_SENS_H) {
        return piece_move_vertical(tetris, 1);
    } else if (sens == PIECE_SENS_H_UP) {
        return piece_move_vertical(tetris, (-1));
    } else {
        return piece_move_horizontal(tetris, sens);
    }
}
