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
    while (check_term_size(tetris)) {
        usleep(1000);
    }
    erase();
    mvprintw(0, 0, "%s", TITLE2);
    color_init();
    display_menu(tetris);
    display_board(tetris);
    use_default_colors();
    refresh();
    return EXIT_SUCCESS;
}
