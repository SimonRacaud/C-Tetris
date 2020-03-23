/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-23T10:46:51+01:00 | Author: simon
*/

#include "pieces_t.h"

int count_tetriminos(pieces_t *pieces)
{
    int count = 0;

    for (int i = 0; i < pieces->size; i++) {
        if (pieces->pc[i].name[0] != '\0') {
            count++;
        }
    }
    return count;
}
