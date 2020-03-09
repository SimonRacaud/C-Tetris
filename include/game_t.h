/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef GAME_H
#define GAME_H

#include "config_t.h"
#include "pieces_t.h"

typedef struct game {
    config_t conf;
    pieces_t terminimos;
    tetrminimo_t piece;
    coord_t piece_coord;
    char **map;
    int score;
    int high_score;
    int lines;
    int level;
    clock_t time;
} game_t;

#endif
