/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-18T08:54:52+01:00 | Author: simon
*/

#include "tetris.h"

void color_init(void)
{
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_CYAN);
    init_pair(2, COLOR_CYAN, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_RED, COLOR_BLUE);
    init_pair(5, COLOR_BLUE, COLOR_GREEN);
    init_pair(6, COLOR_GREEN, COLOR_MAGENTA);
    init_pair(7, COLOR_MAGENTA, COLOR_YELLOW);
}
