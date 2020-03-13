/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-11T16:51:30+01:00 | Author: simon
*/

#include "tetris.h"

extern const int TITLE_HEIGHT;
extern const int TITLE_WIDTH;

extern const int PANEL_HEIGHT;
extern const int PANEL_WIDTH;

int window_create(game_t *tetris)
{
    window_t *board = &tetris->board;
    window_t *menu = &tetris->menu;

    initscr();
    tetris->board.width = tetris->conf.map_width + 2;
    tetris->board.height = tetris->conf.map_height + 3;
    tetris->board.pos = (coord_t){TITLE_HEIGHT, 0};
    tetris->menu.width = PANEL_WIDTH;
    if (tetris->board.height > PANEL_HEIGHT)
        tetris->menu.height = tetris->board.height;
    else
        tetris->menu.height = PANEL_HEIGHT;
    tetris->menu.pos = (coord_t){0, 0};
    board->w = subwin(stdscr, board->height, board->width, TITLE_HEIGHT, 0);
    menu->w = subwin(stdscr, menu->height, menu->width, TITLE_HEIGHT,
    board->width);
    refresh();
    return EXIT_SUCCESS;
}

void window_destroy(game_t *game)
{
    delwin(game->menu.w);
    delwin(game->board.w);
    endwin();
}
