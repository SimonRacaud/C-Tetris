/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-12T14:23:20+01:00 | Author: simon
*/

#include "tetris.h"

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

extern const int LEFT_KEY_ID;
extern const int RIGHT_KEY_ID;
extern const int UP_KEY_ID ;
extern const int DOWN_KEY_ID;

void config_init_default(config_t *conf)
{
    conf->start_level = INIT_START_LEVEL;
    conf->my_key_left[0] = 0;
    conf->my_key_right[0] = 0;
    conf->my_key_turn[0] = 0;
    conf->my_key_drop[0] = 0;
    my_strncpy(conf->my_key_quit, INIT_KEY_QUIT, 4);
    my_strncpy(conf->my_key_pause, INIT_KEY_PAUSE, 4);
    conf->map_height = INIT_MAP_HEIGHT;
    conf->map_width = INIT_MAP_WIDTH;
    conf->hide_next_tetrimino = INIT_HIDE_NEXT_TERMI;
    conf->debug_mode = INIT_DEBUG_MODE;
}

void config_init_spec_key(config_t *conf)
{
    if (!conf->my_key_left)
        my_strncpy(conf->my_key_left, conf->special_key[LEFT_KEY_ID], 4);
    if (!conf->my_key_right)
        my_strncpy(conf->my_key_right, conf->special_key[RIGHT_KEY_ID], 4);
    if (!conf->my_key_turn)
        my_strncpy(conf->my_key_turn, conf->special_key[UP_KEY_ID], 4);
    if (!conf->my_key_drop)
        my_strncpy(conf->my_key_drop, conf->special_key[DOWN_KEY_ID], 4);
}
