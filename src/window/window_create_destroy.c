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

static int get_max_piece_height_width(pieces_t *pieces, int *max_height,
int *max_width)
{
    if (!max_height || !max_width)
        return EXIT_ERROR;
    (*max_height) = 0;
    (*max_width) = 0;
    for (ssize_t i = 0; i < pieces->size; i++) {
        if (pieces->pc[i].mtx == NULL)
            continue;
        if (pieces->pc[i].height > (*max_height)) {
            (*max_height) = pieces->pc[i].height;
        }
        if (pieces->pc[i].width > (*max_width)) {
            (*max_width) = pieces->pc[i].width;
        }
    }
    return EXIT_SUCCESS;
}

static void window_compute_size(game_t *tetris)
{
    int max_p_height = 0;
    int max_p_width = 0;

    get_max_piece_height_width(&tetris->pieces, &max_p_height, &max_p_width);
    tetris->board.width = tetris->conf.map_width + 2;
    tetris->board.height = tetris->conf.map_height + 2;
    tetris->board.pos = (coord_t){TITLE_HEIGHT, 0};
    tetris->menu.width = PANEL_WIDTH;
    tetris->menu.height = (PANEL_HEIGHT + max_p_height + 1);
    if (tetris->menu.width < max_p_width) {
        tetris->menu.width = max_p_width;
    }
    if (tetris->board.height > tetris->menu.height) {
        tetris->menu.height = tetris->board.height;
    }
}

int window_create(game_t *tetris)
{
    window_t *board = &tetris->board;
    window_t *menu = &tetris->menu;

    initscr();
    timeout(0);
    curs_set(0);
    window_compute_size(tetris);
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
