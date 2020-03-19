/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:20:49+01:00 | Author: simon
*/

#include "tetris.h"

extern const int NB_KEY;

void game_destroy(game_t *tetris)
{
    tetrimino_destroy(tetris->next_piece);
    free(tetris->next_piece);
    tetrimino_destroy(tetris->ppiece.piece);
    free(tetris->ppiece.piece);
    pieces_destroy(&tetris->pieces);
    for (int i = 0; i < tetris->conf.map_height; i++) {
        free(tetris->map[i]);
    }
    for (int i = 0; i < NB_KEY; i++)
        free(tetris->conf.special_key[i]);
    free(tetris->conf.special_key);
    free(tetris->map);
}
