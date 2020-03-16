/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T11:50:39+01:00 | Author: simon
*/

#include "tetris.h"

static void write_piece(game_t *tetris, player_piece_t *piece)
{
    size_t end_point_y = piece->coord.y + piece->piece.height;
    size_t end_point_x = piece->coord.x + piece->piece.width;
    size_t piece_x = 0;
    size_t piece_y = 0;

    for (size_t y = piece->coord.y; y < end_point_y; y++) {
        for (size_t x = piece->coord.x; x < end_point_x; x++) {
            piece_x = x - piece->coord.x;
            piece_y = y - piece->coord.y;
            tetris->map[y][x] = piece->piece.mtx[piece_y][piece_x];
        }
    }
}

static bool piece_is_in_map_range(game_t *tetris, player_piece_t *piece)
{
    coord_t map = {tetris->conf.map_width, tetris->conf.map_height};

    if (piece->coord.x < 0 || piece->coord.x >= map.x) {
        return false;
    } else if (piece->coord.y < 0 || piece->coord.y >= map.y) {
        return false;
    }
    if ((piece->coord.x + piece->piece.width) < 0 ||
        (piece->coord.x + piece->piece.width) >= map.x) {
        return false;
    } else if ((piece->coord.y + piece->piece.height) < 0 ||
        (piece->coord.y + piece->piece.height) >= map.y) {
        return false;
    }
    return true;
}

int write_on_map(game_t *tetris)
{
    player_piece_t *piece = &tetris->ppiece;

    if (!piece_is_in_map_range(tetris, piece)) {
        return EXIT_FAILURE;
    } else {
        write_piece(tetris, piece);
    }
    return EXIT_SUCCESS;
}
