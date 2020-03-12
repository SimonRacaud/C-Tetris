/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef CONF_H
#define CONF_H

#include <stdbool.h>

typedef struct config {
    int start_level;
    char my_key_left[4];
    char my_key_right[4];
    char my_key_turn[4];
    char my_key_drop[4];
    char my_key_quit[4];
    char my_key_pause[4];
    int map_height;
    int map_width;
    bool hide_next_tetrimino;
    bool debug_mode;
    char **special_key;
} config_t;

#endif
