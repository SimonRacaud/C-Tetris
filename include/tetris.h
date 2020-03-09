/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef TETRIS_H
#define TETRIS_H

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "my.h"

typedef struct coord {
    int x;
    int y;
} coord_t;

#include "game_t.h"

// Base Functions

int usage(int status);


// Tools Functions
bool have_str_in_array(char **array, int size, const char *str);

#endif
