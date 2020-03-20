/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:23:20+01:00 | Author: simon
*/

#include "tetris.h"

extern const char *PATH_TETRIMINOS;
extern const char *TETRIMINO_CHAR;
extern const char *TETRIMINO_EXT;

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
    word_array_destroy(header);
    return EXIT_SUCCESS;
}

static char **load_piece_content(tetrimino_t *tetri, char *filename)
{
    char *filepath = merge_path_filename(PATH_TETRIMINOS, filename);
    char **file;

    if (!filepath) {
        tetri->mtx = NULL;
        return NULL;
    }
    file = read_file(filepath);
    tetri->name = get_filename_without_ext(filename);
    tetri->mtx = NULL;
    if (!tetri->name || !file) {
        return NULL;
    }
    if (!file || word_array_len(file) < 2) {
        word_array_destroy(file);
        free(filepath);
        return NULL;
    }
    free(filepath);
    return file;
}

static int matrix_create(tetrimino_t *tetri, char **file)
{
    int len = 0;

    for (int i = 1; file[i]; i++) {
        if (!have_only_correct_char_in_str(file[i], TETRIMINO_CHAR))
            return EXIT_ERROR;
        len++;
        if (my_strlen(file[i]) > tetri->width || tetri->width <= 0)
            len = (-1);
    }
    if (len != tetri->height) {
        return EXIT_ERROR;
    }
    tetri->mtx = malloc(sizeof(char *) * len);
    if (!tetri->mtx)
        return EXIT_FAILURE;
    free(file[0]);
    for (int i = 0; i < len; i++)
        tetri->mtx[i] = file[i + 1];
    free(file);
    return EXIT_SUCCESS;
}

static int create_piece_matrix(tetrimino_t *tetri, char **file)
{
    int ret;

    ret = matrix_create(tetri, file);
    if (ret == EXIT_ERROR) {
        my_putstr_error(tetri->name);
        my_putstr_error(" : matrix error\n");
        tetri->mtx = NULL;
        word_array_destroy(file);
        return EXIT_SUCCESS;
    } else if (ret == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int load_piece(tetrimino_t *tetrimino, char *filename, coord_t *map_size)
{
    char **file = NULL;

    if (check_piece_file_extension(tetrimino, filename))
        return EXIT_SUCCESS;
    file = load_piece_content(tetrimino, filename);
    if (!file)
        return EXIT_SUCCESS;
    if (load_piece_header(tetrimino, file[0]) == EXIT_FAILURE) {
        tetrimino->mtx = NULL;
        return EXIT_SUCCESS;
    }
    if (check_piece_parameters(tetrimino, map_size) == false) {
        tetrimino->mtx = NULL;
        word_array_destroy(file);
        return EXIT_SUCCESS;
    }
    if (create_piece_matrix(tetrimino, file) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
