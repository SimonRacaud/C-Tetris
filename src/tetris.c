/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T13:58:20+01:00 | Author: simon
*/

#include "tetris.h"

int tetris(int argc, char **argv, char **env)
{
    game_t tetris;

    if (game_init(&tetris, argv, argc, env) == EXIT_FAILURE)
        return EXIT_ERROR;
    if (tetris.conf.debug_mode) {
        if (show_debug_screen(&tetris) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    if (window_create(&tetris, false) == EXIT_FAILURE)
        return EXIT_ERROR;
    if (game_play(&tetris) == EXIT_FAILURE)
        return EXIT_ERROR;
    game_destroy(&tetris);
    window_destroy(&tetris, false);
    return EXIT_SUCCESS;
}
