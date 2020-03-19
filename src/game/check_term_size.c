/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-19T11:44:14+01:00 | Author: simon
*/

#include "tetris.h"

static bool is_term_too_small(game_t *tetris)
{
    int game_width;
    int game_height;

    game_width = tetris->board.width + tetris->menu.width;
    game_height = tetris->board.height;
    if (tetris->menu.height > game_height)
        game_height = tetris->menu.height;
    game_height += 2;
    game_width += 2;
    if (COLS < game_width || LINES < game_height) {
        return true;
    }
    return false;
}

bool check_term_size(game_t *tetris)
{
    if (is_term_too_small(tetris)) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "TOO SMALL TERMINAL");
        refresh();
        return true;
    }
    return false;
}
