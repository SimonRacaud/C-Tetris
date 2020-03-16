/*
** EPITECH PROJECT, 2019
** player_pieces
** File description:
** player_pieces
*/

#include "tetris.h"

extern char PIECE_CHAR;

static void color_init(void)
{
    start_color();
    init_pair(1, COLOR_YELLOW, 0);
    init_pair(2, COLOR_CYAN, 0);
    init_pair(3, COLOR_WHITE, 0);
    init_pair(4, COLOR_RED, 0);
    init_pair(5, COLOR_BLUE, 0);
    init_pair(6, COLOR_GREEN, 0);
    init_pair(7, COLOR_MAGENTA, 0);
}

static void display_tetriminos(game_t *tetris, window_t *board, int x, int y)
{
    color_init();
    if (tetris->ppiece.piece->mtx[y][x] == PIECE_CHAR) {
        wattron(board->w, COLOR_PAIR(tetris->ppiece.piece->color));
        mvwaddch(board->w, tetris->ppiece.coord.y + y,
            tetris->ppiece.coord.x + x, tetris->ppiece.piece->mtx[y][x]);
        wattroff(board->w, COLOR_PAIR(tetris->ppiece.piece->color));
    }
}

void display_player_pieces(game_t *tetris, window_t *board)
{
    for (int y = 0; y < tetris->ppiece.piece->height; y++)
        for (int x = 0; x < tetris->ppiece.piece->width; x++)
            display_tetriminos(tetris, board, x, y);
}
