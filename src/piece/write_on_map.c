/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T11:50:39+01:00 | Author: simon
*/

#include "tetris.h"

extern const char PIECE_CHAR;

static void write_piece(game_t *tetris, player_piece_t *ppiece)
{
    size_t end_point_y = ppiece->coord.y + ppiece->piece->height;
    size_t end_point_x = ppiece->coord.x + ppiece->piece->width;

    for (size_t y = ppiece->coord.y; y < end_point_y; y++) {
        for (size_t x = ppiece->coord.x; x < end_point_x; x++) {
            if (tetris->map[y][x] == PIECE_CHAR) {
                tetris->map[y][x] = ppiece->piece->color;
            }
        }
    }
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
