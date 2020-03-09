/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef PIECES_H
#define PIECES_H

typedef struct tetrminimo {
    char **piece;
    int height;
    int width;
    int color;
} tetrminimo_t;

typedef struct pieces {
    tetrminimo_t *pieces;
    int size;
} pieces_t;

#endif
