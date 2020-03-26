/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-26T14:12:51+01:00 | Author: x
*/

#include "tetris.h"

extern const struct option LONG_OPTIONS[];

static int get_idx_option_name(char *arg)
{
    int start_idx = 1;
    int opt_idx = -1;

    if (my_strlen(arg) <= 3) {
        return -1;
    }
    for (ssize_t i = start_idx; i < (start_idx + 6); i++) {
        if (my_strcmp((arg + 2), LONG_OPTIONS[i].name) == 0) {
            opt_idx = (i - 1);
        }
    }
    return opt_idx;
}

bool check_for_option_name(char *arg, config_t *conf, int idx_key)
{
    int idx = get_idx_option_name(arg);

    if (idx == -1) {
        conf->key_ptr[idx_key] = &(conf->key[idx_key][0]);
        return false;
    }
    conf->key[idx_key][0] = '\0';
    conf->key_ptr[idx_key] = &(conf->key[idx][0]);
    return true;
}
