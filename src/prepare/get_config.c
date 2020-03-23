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
extern const char *INIT_KEY_LEFT;
extern const char *INIT_KEY_RIGHT;
extern const char *INIT_KEY_TURN;
extern const char *INIT_KEY_DROP;
extern const char *INIT_KEY_QUIT;
extern const char *INIT_KEY_PAUSE;
extern const int INIT_MAP_HEIGHT;
extern const int INIT_MAP_WIDTH;
extern const bool INIT_DEBUG_MODE;
extern const bool INIT_HIDE_NEXT_TERMI;

static int apply_option(char index, config_t *conf)
{
    if (apply_option_key_piece(conf, index) == EXIT_FAILURE) {
        my_putstr_error("Key piece error\n");
        return EXIT_FAILURE;
    }
    if (apply_option_key_menu(conf, index) == EXIT_FAILURE) {
        my_putstr_error("Key Menu error\n");
        return EXIT_FAILURE;
    }
    if (apply_option_misc(conf, index) == EXIT_FAILURE) {
        my_putstr_error("Misc option error\n");
        return EXIT_FAILURE;
    }
    if (apply_option_map_size(conf, index) == EXIT_FAILURE) {
        my_putstr_error("Map size error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static bool check_key(const char *key)
{
    int len = my_strlen(key);

    if (len < 1) {
        return false;
    }
    if (len == 1) {
        return true;
    } else if (len == 3) {
        if (my_strncmp(key, "\eO", 2) == 0)
            return true;
    }
    return false;
}

static int check_for_option_error(config_t *conf, char **argv,
int argc)
{
    if (conf->start_level < 1)
        return EXIT_FAILURE;
    if (conf->map_width < 1 || conf->map_height < 1)
        return EXIT_FAILURE;
    if (!check_key(conf->key[LEFT_KEY]) || !check_key(conf->key[RIGHT_KEY]))
        return EXIT_FAILURE;
    if (!check_key(conf->key[TURN_KEY]) || !check_key(conf->key[DROP_KEY]))
        return EXIT_FAILURE;
    if (!check_key(conf->key[QUIT_KEY]) || !check_key(conf->key[PAUSE_KEY]))
        return EXIT_FAILURE;
    if (check_argv(argv, argc) == true) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int get_config(config_t *conf, char **argv, int argc, char **env)
{
    int ret;

    config_init_default(conf);
    while ((ret = getopt_long(argc, argv, OPTIONS, LONG_OPTIONS, 0)) != -1) {
        if (ret == '?')
            return usage(EXIT_FAILURE, argv[0]);
        if (apply_option((char)ret, conf) == EXIT_FAILURE) {
            my_putstr_error("Option error : invalid option\n");
            return EXIT_FAILURE;
        }
    }
    conf->special_key = get_special_key(env);
    if (!conf->special_key)
        return EXIT_FAILURE;
    config_init_spec_key(conf);
    if (check_for_option_error(conf, argv, argc) == EXIT_FAILURE) {
        my_putstr_error("Option error : value error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
