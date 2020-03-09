/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T15:30:52+01:00 | Author: simon
*/

#include "tetris.h"

int apply_option_key_piece(config_t *conf, char index)
{
    if (index == 'l') {
        if (my_get_check_nbr(optarg, &conf->key_left, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (index == 'r') {
        if (my_get_check_nbr(optarg, &conf->key_right, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (index == 't') {
        if (my_get_check_nbr(optarg, &conf->key_turn, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (index == 'd') {
        if (my_get_check_nbr(optarg, &conf->key_drop, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int apply_option_key_other(config_t *conf, char index)
{

    if (index == 'q') {
        if (my_get_check_nbr(optarg, &conf->key_quit, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (index == 'p') {
        if (my_get_check_nbr(optarg, &conf->key_pause, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int apply_option_misc(config_t *conf, char index)
{
    if (index == 'L') {
        if (my_get_check_nbr(optarg, &conf->start_level, 0) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (index == 'w') {
        conf->hide_next_tetrimino = true;
    }
    if (index == 'D') {
        conf->debug_mode = true;
    }
    return EXIT_SUCCESS;
}

int apply_option_map_size(config_t *conf, char index)
{
    char **wa = NULL;

    if (index == 's') {
        wa = my_str_to_word_array(optarg, ",");
        if (word_array_len(wa) != 2) {
            my_putstr_error("--map-size={row,col} : map size error\n");
            return EXIT_FAILURE;
        }
        if (my_get_check_nbr(wa[0], &conf->map_height, " ") == EXIT_FAILURE)
            return EXIT_FAILURE;
        if (my_get_check_nbr(wa[1], &conf->map_width, " ") == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
