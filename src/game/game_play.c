/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T16:24:50+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *TITLE2;

int game_play(game_t *tetris)
{
    // TEMP
    printw("%s", TITLE2);
    mvwprintw(tetris->board.w, 1, 1, "GAME BOARD");
    mvwprintw(tetris->menu.w, 1, 1, "Ceci est la fenetre du MENU");
    refresh();
    wrefresh(tetris->menu.w);
    wrefresh(tetris->board.w);
    getch();
    return tetris->exit_status;
}
