/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-17T11:50:39+01:00 | Author: simon
*/

#include "tetris.h"

bool piece_is_in_map_range(game_t *tetris, player_piece_t *piece)
{
    coord_t map = {tetris->conf.map_width, tetris->conf.map_height};

    if (piece->coord.x <= 0 ||
            (piece->coord.x + piece->piece->width - 1) > map.x) {
        return false;
    } else if (piece->coord.y < 0 ||
            (piece->coord.y + piece->piece->height) > map.y) {
        return false;
    }
    return true;
}
