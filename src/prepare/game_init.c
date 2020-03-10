/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:20:49+01:00 | Author: simon
*/

#include "tetris.h"

static void game_init_struct(game_t *tetris)
{
    tetris->map = NULL;
    tetris->score = 0;
    tetris->high_score = 0;
    tetris->lines = 0;
    tetris->level = 0;
    tetris->time = 0;
}

static int game_map_create(game_t *tetris)
{
    tetris->map = malloc(sizeof(char *) * tetris->conf.map_height);
    if (!tetris)
        return EXIT_FAILURE;
    for (int i = 0; i < tetris->conf.map_height; i++) {
        tetris->map[i] = malloc(sizeof(char) * tetris->conf.map_width);
        if (!tetris->map[i])
            return EXIT_FAILURE;
        for (int x = 0; x < tetris->conf.map_width; x++)
            tetris->map[i][x] = ' ';
    }
    return EXIT_SUCCESS;
}

int game_init(game_t *tetris, char **argv, int argc)
{
    game_init_struct(tetris);
    if (get_config(&tetris->conf, argv, argc) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (load_tetriminos(&tetris->pieces) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (game_map_create(tetris) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
