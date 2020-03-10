/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-10T10:19:08+01:00 | Author: simon
*/

#include "tetris.h"

void pieces_destroy(pieces_t *pieces)
{
    for (int i = 0; i < pieces->size; i++) {
        free(pieces->pc[i].name);
        if (!pieces->pc[i].mtx)
            continue;
        for (int j = 0; j < pieces->pc[i].height; j++)
            free(pieces->pc[i].mtx[j]);
        free(pieces->pc[i].mtx);
    }
    free(pieces->pc);
}
