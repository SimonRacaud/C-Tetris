/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T17:53:44+01:00 | Author: simon
*/

#include "tetris.h"

int display_board(game_t *tetris)
{
    window_t *board = &tetris->board;

    wresize(board->w, board->height, board->width);
    display_pieces(tetris);
    display_player_piece(tetris, board);
    box(board->w, ACS_VLINE, ACS_HLINE);
    return EXIT_SUCCESS;
}
