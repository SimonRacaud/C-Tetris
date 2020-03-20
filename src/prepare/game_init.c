/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:20:49+01:00 | Author: simon
*/

#include "tetris.h"

extern const char BACKG_CHAR;
extern float REFRESH_TIME;

static void game_init_struct(game_t *tetris)
{
    tetris->ppiece.piece = NULL;
    tetris->score = 0;
    tetris->status = RUNNING;
    tetris->high_score = 0;
    tetris->line = 0;
    tetris->level = tetris->conf.start_level;
    tetris->time_sub = 0;
    tetris->exit_status = EXIT_SUCCESS;
    tetris->refresh_time = REFRESH_TIME;
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
            tetris->map[i][x] = BACKG_CHAR;
    }
    return EXIT_SUCCESS;
}

int game_init(game_t *tetris, char **argv, int argc, char **env)
{
    coord_t map_size;

    srand((unsigned int)clock());
    game_init_struct(tetris);
    if (get_config(&tetris->conf, argv, argc, env) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    map_size = (coord_t){tetris->conf.map_width, tetris->conf.map_height};
    if (load_tetriminos(&tetris->pieces, &map_size) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (game_map_create(tetris) == EXIT_FAILURE)
        return EXIT_FAILURE;
    game_init_struct(tetris);
    if (set_next_piece(tetris) == EXIT_FAILURE)
        return EXIT_FAILURE;
    set_game_speed(tetris);
    return EXIT_SUCCESS;
}
