/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "pieces_t.h"
#include "tetris.h"

static char **get_new_matrix(int x, int y)
{
    char **array = malloc(sizeof(char *) * y);

    if (!array)
        return NULL;
    for (int i = 0; i < y; i++) {
        array[i] = malloc(sizeof(char) * (x + 1));
        if (!array[i])
            return NULL;
        array[i][x] = '\0';
    }
    return array;
}

static void matrix_rotate(char **new, tetrimino_t *piece)
{
    for (int y = 0; y < piece->width; y++)
        for (int x = piece->height - 1; x >= 0; x--) {
            if (piece->mtx[x][y] != 0)
                new[y][piece->height - x - 1] = piece->mtx[x][y];
            else
                new[y][piece->height - x - 1] = ' ';
        }
}

static void error_manage(game_t *tetris, char **old)
{
    int temp;

    if (piece_have_collision(tetris)) {
        for (int i = 0; i < tetris->ppiece.piece->height; i++)
            free(tetris->ppiece.piece->mtx[i]);
        free(tetris->ppiece.piece->mtx);
        tetris->ppiece.piece->mtx = old;
        temp = tetris->ppiece.piece->height;
        tetris->ppiece.piece->height = tetris->ppiece.piece->width;
        tetris->ppiece.piece->width = temp;
    }
    else {
        for (int i = 0; i < tetris->ppiece.piece->width; i++)
            free(old[i]);
        free(old);
    }
}

int rotate(game_t *tetris)
{
    int temp;
    tetrimino_t *piece = tetris->ppiece.piece;
    char **new = get_new_matrix(piece->height, piece->width);
    char **tmp;

    if (!new)
        return EXIT_ERROR;
    matrix_rotate(new, piece);
    tmp = piece->mtx;
    piece->mtx = new;
    temp = piece->height;
    piece->height = piece->width;
    piece->width = temp;
    error_manage(tetris, tmp);
    return EXIT_SUCCESS;
}
