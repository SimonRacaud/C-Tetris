/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-23T12:06:08+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *OPTIONS;

bool check_param_exist(const char *param)
{
    for (size_t i = 1; param[i] != '\0'; i++) {
        if (!have_char_in_string(param[i], OPTIONS)) {
            return true;
        }
    }
    return false;
}

bool check_multiple_arg(char **argv, const int argc,
const char *arg, int idx)
{
    bool ret = false;

    for (ssize_t i = 1; i < argc; i++) {
        if (i == idx || !argv || argv[i][0] != '-') {
            continue;
        } else if (my_strncmp(argv[i], "--", 2) == 0) {
            continue;
        }
        for (ssize_t j = 1; arg[j] != '\0'; j++) {
            ret = ret | have_char_in_string(arg[j], argv[i]);
        }
        if (ret == true)
            return true;
    }
    return false;
}

bool check_argv(char **argv, const int argc)
{
    bool prev_is_param = false;
    bool ret = false;

    for (ssize_t i = 1; i < argc; i++) {
        if (argv && argv[i][0] == '-' && argv[i][1] != '-') {
            prev_is_param = true;
            ret = check_param_exist(argv[i]);
            ret = ret | check_multiple_arg(argv, argc, argv[i], i);
        } else if (argv && argv[i][0] == '-') {
            prev_is_param = true;
        }
        if (argv && argv[i][0] != '-' && !prev_is_param) {
            my_putstr_error("check_argv : alone value\n");
            return true;
        } else if (ret ==  true) {
            my_putstr_error("check_argv : wrong or multiple parameter\n");
            return true;
        }
    }
    return false;
}
