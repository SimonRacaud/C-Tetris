/*
** EPITECH PROJECT, 2019
** player_pieces
** File description:
** player_pieces
*/

#include "tetris.h"

extern char PIECE_CHAR;

static void display_player_piece_char(game_t *tetris, window_t *board, int x,
int y)
{
    if (tetris->ppiece.piece->mtx[y][x] == PIECE_CHAR) {
        wattron(board->w, COLOR_PAIR(tetris->ppiece.piece->color));
        mvwaddch(board->w, tetris->ppiece.coord.y + y + 1,
            tetris->ppiece.coord.x + x, tetris->ppiece.piece->mtx[y][x]);
        wattroff(board->w, COLOR_PAIR(tetris->ppiece.piece->color));
    }
}

void display_player_piece(game_t *tetris, window_t *board)
{
    for (ssize_t y = 0; y < tetris->ppiece.piece->height; y++) {
        for (ssize_t x = 0; x < tetris->ppiece.piece->width; x++) {
            display_player_piece_char(tetris, board, x, y);
        }
    }
}
