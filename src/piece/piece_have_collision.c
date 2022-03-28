/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T21:04:36+01:00 | Author: simon
*/

#include "tetris.h"

extern const char PIECE_CHAR;
extern const char BACKG_CHAR;

static bool have_collision_with_other_piece(game_t *tetris,
player_piece_t *piece)
{
    size_t end_point_y = piece->coord.y + piece->piece->height - 1;
    size_t end_point_x = piece->coord.x + piece->piece->width - 1;
    size_t piece_x = 0;
    size_t piece_y = 0;

    for (size_t y = piece->coord.y; y <= end_point_y; y++) {
        for (size_t x = piece->coord.x; x <= end_point_x; x++) {
            piece_x = x - piece->coord.x;
            piece_y = y - piece->coord.y;
            if (tetris->map[y][x - 1] != BACKG_CHAR &&
                    piece->piece->mtx[piece_y][piece_x] == PIECE_CHAR) {
                return true;
            }
        }
    }
    return false;
}

bool piece_have_collision(game_t *tetris)
{
    player_piece_t *pp = &tetris->ppiece;

    if (!piece_is_in_map_range(tetris, pp)) {
        return true;
    }
    if (have_collision_with_other_piece(tetris, pp)) {
        return true;
    }
    return false;
}
