/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main function
*/

#include "tetris.h"

int main(int argc, char **argv, char **env)
{
    bool show_help = have_str_in_array(argv, argc, "-h");

    show_help = show_help || have_str_in_array(argv, argc, "--help");
    if (show_help) {
        return usage(EXIT_SUCCESS, argv[0]);
    } else {
        return tetris(argc, argv, env);
    }
    return EXIT_SUCCESS;
}
