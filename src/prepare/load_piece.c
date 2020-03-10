/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:23:20+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *PATH_TETRIMINOS;

static int load_piece_header(tetrimino_t *tetri, char *first_line)
{
    char **header = my_str_to_word_array(first_line, " ");

    if (!header || word_array_len(header) != 3) {
        return EXIT_FAILURE;
    }
    if (my_get_check_nbr(header[0], &(tetri->width), NULL) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (my_get_check_nbr(header[1], &(tetri->height), NULL) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (my_get_check_nbr(header[2], &(tetri->color), NULL) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int load_piece(tetrimino_t *tetrimino, char *filename)
{
    char *filepath = merge_path_filename(PATH_TETRIMINOS, filename);
    char **file = read_file(filepath);

    if (!filepath) {
        my_putstr_error("load_piece : filepath error\n");
        return EXIT_FAILURE;
    }
    tetrimino->name = get_filename_without_ext(filename);
    if (!tetrimino->name)
        return EXIT_FAILURE;
    if (!file || word_array_len(file) < 2) {
        tetrimino->mtx = NULL;
        return EXIT_SUCCESS;
    }
    if (load_piece_header(tetrimino, file[0]) == EXIT_FAILURE) {
        tetrimino->mtx = NULL;
        return EXIT_SUCCESS;
    }
    free(filepath);
    word_array_destroy(file);
    return EXIT_SUCCESS;
}
