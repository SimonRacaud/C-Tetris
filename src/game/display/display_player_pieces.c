/*
** EPITECH PROJECT, 2019
** player_pieces
** File description:
** player_pieces
*/

#include "tetris.h"

extern char PIECE_CHAR;

static void display_tetriminos(game_t *tetris, window_t *board, int x, int y)
{
    if (tetris->ppiece.piece->mtx[y][x] == PIECE_CHAR)
        mvwprintw(board->w, tetris->ppiece.coord.y + y,
            tetris->ppiece.coord.x + x, "%c", tetris->ppiece.piece->mtx[y][x]);
}

void display_player_pieces(game_t *tetris, window_t *board)
{
    for (int y = 0; y < tetris->ppiece.piece->height; y++)
        for (int x = 0; x < tetris->ppiece.piece->width; x++)
            display_tetriminos(tetris, board, x, y);
}