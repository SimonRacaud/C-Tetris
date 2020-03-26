/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T13:58:20+01:00 | Author: simon
*/

#include "tetris.h"

static void smkx_mode(void)
{
    char *my_term = tigetstr("smkx");
    if (my_term)
        write(1, my_term, my_strlen(my_term));
}

int tetris(int argc, char **argv, char **env)
{
    game_t tetris;

    if (game_init(&tetris, argv, argc, env) == EXIT_FAILURE) {
        return usage(EXIT_ERROR, argv[0]);
    }
    if (tetris.conf.debug_mode) {
        if (show_debug_screen(&tetris) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    if (window_create(&tetris, false) == EXIT_FAILURE)
        return EXIT_ERROR;
    smkx_mode();
    if (game_play(&tetris) == EXIT_FAILURE)
        return EXIT_ERROR;
    game_destroy(&tetris);
    window_destroy(&tetris, false);
    return EXIT_SUCCESS;
}
