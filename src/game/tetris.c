/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T13:58:20+01:00 | Author: simon
*/

#include "tetris.h"

int tetris(int argc, char **argv)
{
    game_t tetris;

    if (game_init(&tetris, argv, argc) == EXIT_FAILURE)
        return EXIT_FAILURE;

    pieces_destroy(&tetris.pieces);
    return EXIT_SUCCESS;
}
