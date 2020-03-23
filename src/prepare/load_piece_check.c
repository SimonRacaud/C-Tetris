/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-20T14:23:20+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *TETRIMINO_EXT;

bool check_piece_file_extension(tetrimino_t *tetrimino, char *filename)
{
    bool right_ext = have_right_file_ext(filename, TETRIMINO_EXT);

    if (!right_ext) {
        tetrimino->mtx = NULL;
        my_putstr_error("tetrimono file : wrong extension\n");
        tetrimino->name = "";
        return true;
    }
    return false;
}

bool check_piece_parameters(tetrimino_t *tet, coord_t *map_size)
{
    if (tet->color < 0) {
        if (tet->name)
            my_putstr_error(tet->name);
        my_putstr_error(" : wrong color\n");
        return false;
    }
    if (tet->width > map_size->x) {
        if (tet->name)
            my_putstr_error(tet->name);
        my_putstr_error(" : bigger than map width\n");
        return false;
    }
    if (tet->height > map_size->y) {
        if (tet->name)
            my_putstr_error(tet->name);
        my_putstr_error(" : bigger than map height\n");
        return false;
    }
    return true;
}

bool check_piece_width(tetrimino_t *tet)
{
    int max_width = 0;
    int curr_width;

    for (ssize_t y = 0; y < tet->height; y++) {
        curr_width = my_strlen(tet->mtx[y]);
        if (curr_width > tet->width) {
            return true;
        }
        if (curr_width > max_width) {
            max_width = curr_width;
        }
    }
    if (max_width != tet->width) {
        return true;
    }
    return false;
}
