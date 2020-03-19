/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-19T11:44:14+01:00 | Author: simon
*/

#include "tetris.h"

extern const int TITLE_HEIGHT;

static bool is_term_too_small(game_t *tetris)
{
    int game_width;
    int game_height;

    game_width = tetris->board.width + tetris->menu.width;
    game_height = tetris->board.height;
    if (tetris->menu.height > game_height)
        game_height = tetris->menu.height;
    game_height += (2 + TITLE_HEIGHT);
    game_width += 2;
    if (COLS < game_width || LINES < game_height) {
        return true;
    }
    return false;
}

bool check_term_size(game_t *tetris)
{
    static bool last_call_return = false;

    if (is_term_too_small(tetris)) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 10, "TOO SMALL TERMINAL");
        refresh();
        last_call_return = true;
        return true;
    } else if (last_call_return) {
        window_destroy(tetris, true);
        window_create(tetris, true);
    }
    last_call_return = false;
    return false;
}
