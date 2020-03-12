/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef GAME_H
#define GAME_H

#include <time.h>
#include "config_t.h"
#include "pieces_t.h"
#include "window_t.h"

typedef struct game {
    int exit_status;
    window_t menu;
    window_t board;
    config_t conf;
    pieces_t pieces;
    player_piece_t ppiece;
    char **map;
    int score;
    int high_score;
    int line;
    int level;
    int time_sub;
} game_t;

#endif
