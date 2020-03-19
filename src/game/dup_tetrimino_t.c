/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "tetris.h"
#include "my.h"

static char **dup_mtx(tetrimino_t *src)
{
    char **mat = malloc(sizeof(char *) * src->height);

    if (!mat)
        return NULL;
    for (int i = 0; i < src->height; i++) {
        mat[i] = malloc(sizeof(char) * src->width);
        if (!mat[i])
            return NULL;
        for (int x = 0; x < src->width; x++)
            mat[i][x] = src->mtx[i][x];
    }
    return mat;
}

tetrimino_t *dup_tetrimino(tetrimino_t *src)
{
    tetrimino_t *my_tetr = malloc(sizeof(tetrimino_t));

    if (!my_tetr)
        return NULL;
    my_tetr->name = my_strdup(src->name);
    if (!my_tetr->name)
        return NULL;
    my_tetr->mtx = dup_mtx(src);
    if (!my_tetr->mtx)
        return NULL;
    my_tetr->color = src->color;
    my_tetr->width = src->width;
    my_tetr->height = src->height;
    return my_tetr;
}