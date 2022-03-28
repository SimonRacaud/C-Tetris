/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-17T20:07:10+01:00 | Author: simon
*/

#include "tetris.h"

extern const char BACKG_CHAR;
extern const char PIECE_CHAR;

void display_pieces(game_t *tetris)
{
    for (ssize_t y = 0; y < tetris->conf.map_height; y++) {
        for (ssize_t x = 0; x < tetris->conf.map_width; x++) {
            if (tetris->map[y][x] == BACKG_CHAR) {
                mvwaddch(tetris->board.w, (y + 1), (x + 1), BACKG_CHAR);
                continue;
            }
            wattron(tetris->board.w, COLOR_PAIR(tetris->map[y][x]));
            mvwaddch(tetris->board.w, (y + 1), (x + 1), PIECE_CHAR);
            wattroff(tetris->board.w, COLOR_PAIR(tetris->map[y][x]));
        }
    }
}
