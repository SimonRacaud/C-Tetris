/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T21:04:36+01:00 | Author: simon
*/

#include "tetris.h"

static void piece_move_vertical(game_t *tetris)
{
    for (ssize_t i = 0; i < tetris->ppiece.speed_y; i++) {
        tetris->ppiece.coord.y++;
        if (piece_have_collision(tetris)) {
            tetris->ppiece.coord.y--;
            tetris->ppiece.is_fall = false;
            break;
        }
    }
}

static void piece_move_horizontal(game_t *tetris, enum piece_move_sens sens)
{
    int shift = 0;

    if (sens == PIECE_SENS_V_LEFT) {
        shift = -1;
    } else if (sens == PIECE_SENS_V_RIGHT) {
        shift = 1;
    } else {
        return;
    }
    tetris->ppiece.coord.x += shift;
    if (piece_have_collision(tetris)) {
        tetris->ppiece.coord.y -= shift;
    }
}

int piece_move(game_t *tetris, enum piece_move_sens sens)
{
    if (sens == PIECE_SENS_H) {
        piece_move_vertical(tetris);
    } else {
        piece_move_horizontal(tetris, sens);
    }
    return EXIT_SUCCESS;
}
