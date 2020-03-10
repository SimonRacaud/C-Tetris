/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:20:49+01:00 | Author: simon
*/

#include "tetris.h"

void game_destroy(game_t *tetris)
{
    pieces_destroy(&tetris->pieces);
    for (int i = 0; i < tetris->conf.map_height; i++) {
        free(tetris->map[i]);
    }
    free(tetris->map);
}
