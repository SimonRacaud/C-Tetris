/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-10T10:19:08+01:00 | Author: simon
*/

#include "tetris.h"

void tetrimino_destroy(tetrimino_t *tet)
{
    if (tet->name[0] != '\0')
        free(tet->name);
    if (!tet->mtx)
        return;
    for (int j = 0; j < tet->height; j++)
        free(tet->mtx[j]);
    free(tet->mtx);
}

void pieces_destroy(pieces_t *pieces)
{
    for (int i = 0; i < pieces->size; i++) {
        tetrimino_destroy(&pieces->pc[i]);
    }
    free(pieces->pc);
}
