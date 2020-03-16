/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T17:53:44+01:00 | Author: simon
*/

#include "tetris.h"

extern char BACKG_CHAR;
extern char PIECE_CHAR;

static void display_map(game_t *tetris, window_t *board, int x, int y)
{
    if (tetris->map[y][x] != BACKG_CHAR) {
        wattron(board->w, COLOR_PAIR(tetris->map[y][x]));
        mvwprintw(board->w, 2 + y, 1 + x, "%c", PIECE_CHAR);
        wattroff(board->w, COLOR_PAIR(tetris->map[y][x]));
    }
    else
        mvwprintw(board->w, 2 + y, 1 + x, "%c", tetris->map[y][x]);
}

int display_board(game_t *tetris)
{
    window_t *board = &tetris->board;

    for (int y = 0; y < tetris->conf.map_height; y++) {
        for (int x = 0; x < tetris->conf.map_width; x++)
            display_map(tetris, board, x, y);
        mvwprintw(board->w, 1, 1, "%c", '\n');
    }
    display_player_pieces(tetris, board);
    mvwprintw(board->w, 1, 1, "GAME BOARD");
    box(board->w, ACS_VLINE, ACS_HLINE);
    return EXIT_SUCCESS;
}
