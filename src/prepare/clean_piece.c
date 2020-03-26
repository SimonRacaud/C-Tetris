/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "tetris.h"

static void rm_space(tetrimino_t *piece, int y)
{
    for (int x = piece->width - 1; x >= 0; x--)
        if (piece->mtx[y][x] == '*') {
            piece->mtx[y][x + 1] = '\0';
            break;
        }
}

static void clean_piece(tetrimino_t *piece)
{
    for (int y = 0; y < piece->height; y++)
        rm_space(piece, y);
}

void clean_tetriminos(tetrimino_t *pc, int size)
{
    for (int i = 0; i < size; i++)
        if (pc[i].mtx)
            clean_piece(&pc[i]);
}