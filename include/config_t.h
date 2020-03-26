/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef CONF_H
#define CONF_H

#include <stdbool.h>

#define LEFT_KEY 0
#define RIGHT_KEY 1
#define TURN_KEY 2
#define DROP_KEY 3
#define QUIT_KEY 4
#define PAUSE_KEY 5

typedef struct config {
    int start_level;
    char key[6][4];
    char *key_ptr[6];
    int map_height;
    int map_width;
    bool hide_next_tetrimino;
    bool debug_mode;
    char **special_key;
} config_t;

#endif
