/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T12:43:38+01:00 | Author: simon
*/

#include "tetris.h"

extern const int INIT_PIECE_SPEEDY;

int set_player_piece(tetrimino_t *next_piece, player_piece_t *ppiece,
game_t *game)
{
    ppiece->coord.x = (int)(game->conf.map_width / 2);
    ppiece->coord.y = 0;
    ppiece->speed_y = INIT_PIECE_SPEEDY;
    ppiece->is_fall = true;
    ppiece->piece = next_piece;
    return EXIT_SUCCESS;
}
