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
    init_pair(1, COLOR_YELLOW, 0);
    init_pair(2, COLOR_CYAN, 0);
    init_pair(3, COLOR_WHITE, 0);
    init_pair(4, COLOR_RED, 0);
    init_pair(5, COLOR_BLUE, 0);
    init_pair(6, COLOR_GREEN, 0);
    init_pair(7, COLOR_MAGENTA, 0);
}