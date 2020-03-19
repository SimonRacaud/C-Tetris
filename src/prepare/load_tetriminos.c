/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T14:23:20+01:00 | Author: simon
*/

#include "tetris.h"
#include <sys/types.h>
#include <dirent.h>

extern const char *PATH_TETRIMINOS;

static int load_pieces_filename(file_list_t **files, int *size)
{
    struct dirent *file;
    DIR *dir = opendir(PATH_TETRIMINOS);

    if (!dir) {
        my_putstr_error("Fail to open tetriminos directory\n");
        return EXIT_FAILURE;
    }
    while ((file = readdir(dir)) != NULL) {
        if (file->d_type != DT_REG)
            continue;
        (*size)++;
        file_list_add(files, file->d_name);
    }
    closedir(dir);
    return EXIT_SUCCESS;
}

static int pieces_create(pieces_t *pieces, file_list_t *files, int size)
{
    file_list_t *ptr = files;

    pieces->size = size;
    pieces->pc = malloc(sizeof(tetrimino_t) * size);
    if (!pieces->pc) {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < size; i++) {
        if (load_piece(&(pieces->pc[i]), ptr->filename) == EXIT_FAILURE)
            return EXIT_FAILURE;
        ptr = ptr->next;
    }
    return EXIT_SUCCESS;
}

int load_tetriminos(pieces_t *pieces)
{
    int count_file = 0;
    file_list_t *files = NULL;

    if (load_pieces_filename(&files, &count_file) == EXIT_FAILURE)
        return EXIT_SUCCESS;
    if (count_file == 0)
        return EXIT_FAILURE;
    if (pieces_create(pieces, files, count_file) == EXIT_FAILURE)
        return EXIT_FAILURE;
    file_list_destroy(files);
    sort_tetriminos(pieces->pc, pieces->size);
    return EXIT_SUCCESS;
}
