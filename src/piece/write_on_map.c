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
    size_t end_point_y = ppiece->coord.y + ppiece->piece->height - 1;
    size_t end_point_x = ppiece->coord.x + ppiece->piece->width - 1;
    size_t piece_x = 0;
    size_t piece_y = 0;

    for (size_t y = ppiece->coord.y; y <= end_point_y; y++) {
        for (size_t x = ppiece->coord.x; x <= end_point_x; x++) {
            piece_x = x - ppiece->coord.x;
            piece_y = y - ppiece->coord.y;
            if (ppiece->piece->mtx[piece_y][piece_x] == '\0') {
                break;
            } else if (ppiece->piece->mtx[piece_y][piece_x] == PIECE_CHAR) {
                tetris->map[y][x - 1] = (char)ppiece->piece->color;
            }
        }
    }
}

int write_on_map(game_t *tetris)
{
    player_piece_t *piece = &tetris->ppiece;

    if (piece_have_collision(tetris)) {
        return EXIT_FAILURE;
    }
    if (!piece_is_in_map_range(tetris, piece)) {
        return EXIT_FAILURE;
    } else {
        write_piece(tetris, piece);
    }
    return EXIT_SUCCESS;
}
