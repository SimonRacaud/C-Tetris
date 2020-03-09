/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef CONF_H
#define CONF_H

typedef struct config {
    int start_level;
    int key_left;
    int key_right;
    int key_trun;
    int key_drop;
    int key_quit;
    int key_pause;
    int map_height;
    int map_width;
    bool hide_next_terminimo;
    bool debug_mode;
} config_t;

#endif
