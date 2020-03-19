/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T17:53:44+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *TITLE2;

int display(game_t *tetris)
{
    erase();
    printw("%s", TITLE2);
    color_init();
    mvprintw(10, 50, "%f", tetris->refresh_time);
    display_menu(tetris);
    display_board(tetris);
    use_default_colors();
    refresh();
    wrefresh(tetris->menu.w);
    wrefresh(tetris->board.w);
    return EXIT_SUCCESS;
}
