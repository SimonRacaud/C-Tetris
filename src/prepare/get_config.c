/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:23:20+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *OPTIONS;
extern const struct option LONG_OPTIONS[];

extern const int INIT_START_LEVEL;
extern const int INIT_KEY_LEFT;
extern const int INIT_KEY_RIGHT;
extern const int INIT_KEY_TURN;
extern const int INIT_KEY_DROP;
extern const int INIT_KEY_QUIT;
extern const int INIT_KEY_PAUSE;
extern const int INIT_MAP_HEIGHT;
extern const int INIT_MAP_WIDTH;
extern const bool INIT_DEBUG_MODE;
extern const bool INIT_HIDE_NEXT_TERMI;

static int apply_option(char index, config_t *conf)
{
    if (apply_option_key_piece(conf, index) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (apply_option_key_other(conf, index) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (apply_option_misc(conf, index) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (apply_option_map_size(conf, index) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static void config_init_default(config_t *conf)
{
    conf->start_level = INIT_START_LEVEL;
    conf->key_left = INIT_KEY_LEFT;
    conf->key_right = INIT_KEY_RIGHT;
    conf->key_turn = INIT_KEY_TURN;
    conf->key_drop = INIT_KEY_DROP;
    conf->key_quit = INIT_KEY_QUIT;
    conf->key_pause = INIT_KEY_PAUSE;
    conf->map_height = INIT_MAP_HEIGHT;
    conf->map_width = INIT_MAP_WIDTH;
    conf->hide_next_tetrimino = INIT_HIDE_NEXT_TERMI;
    conf->debug_mode = INIT_DEBUG_MODE;
}

static int check_for_option_error(config_t *conf)
{
    if (conf->start_level < 1)
        return EXIT_FAILURE;
    if (conf->map_width < 1 || conf->map_height < 1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int get_config(config_t *conf, char **argv, int argc)
{
    int ret;

    config_init_default(conf);
    while ((ret = getopt_long(argc, argv, OPTIONS, LONG_OPTIONS, 0)) != -1) {
        if (apply_option((char)ret, conf) == EXIT_FAILURE) {
            my_putstr_error("Option error : invalid option\n");
            return EXIT_FAILURE;
        }
    }
    debug_display_config(conf);
    if (check_for_option_error(conf) == EXIT_FAILURE) {
        my_putstr_error("Option error : value error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
