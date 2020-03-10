/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef PIECES_H
#define PIECES_H

typedef struct tetrmimino {
    char *name;
    char **mtx;
    int height;
    int width;
    int color;
} tetrimino_t;

typedef struct pieces {
    tetrimino_t *pieces;
    int size;
} pieces_t;

#endif
