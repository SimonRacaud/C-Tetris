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
    char **tab = malloc(sizeof(char *) * y);

    if (!tab)
        return NULL;
    for (int i = 0; i < y; i++) {
        tab[i] = malloc(sizeof(char) * (x + 1));
        if (!tab[i])
            return NULL;
        tab[i][x] = '\0';
    }
    return tab;
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

int rotate(tetrimino_t *piece)
{
    int temp = 0;
    char **new = get_new_matrix(piece->height, piece->width);

    if (!new)
        return EXIT_ERROR;
    matrix_rotate(new, piece);
    for (int i = 0; i < piece->height; i++)
        free(piece->mtx[i]);
    free(piece->mtx);
    piece->mtx = new;
    temp = piece->height;
    piece->height = piece->width;
    piece->width = temp;
    return EXIT_SUCCESS;
}