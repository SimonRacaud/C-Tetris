/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T08:24:41+01:00 | Author: simon
*/

#ifndef WIN_H
#define WIN_H

#include <ncurses.h>
#include "pieces_t.h"

typedef struct window {
    WINDOW *w;
    int width;
    int height;
    coord_t pos;
} window_t;

#endif
