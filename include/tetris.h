/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef TETRIS_H
#define TETRIS_H

typedef struct coord {
    int x;
    int y;
} coord_t;

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include "my.h"
#include "game_t.h"

#define EXIT_ERROR 84

// Base Functions

int usage(int status);
int tetris(int argc, char **argv);

// Tools Functions
bool have_str_in_array(char **array, int size, const char *str);
int my_get_check_nbr(char *str, int *nbr, const char *ignore);

// Prepare and Init
int game_init(game_t *tetris, char **argv, int argc);
int get_config(config_t *conf, char **argv, int argc);
int load_tetriminos(pieces_t *pieces);

int apply_option_key_piece(config_t *conf, char index);
int apply_option_key_other(config_t *conf, char index);
int apply_option_misc(config_t *conf, char index);
int apply_option_map_size(config_t *conf, char index);

 void debug_display_config(config_t *config); // DEBUG

#endif
