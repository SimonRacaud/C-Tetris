/*
** EPITECH PROJECT, 2019
** colision.c
** File description:
** tetris
*/

#include <stdbool.h>
#include "tetris.h"

extern char PIECE_CHAR;
extern char BACKG_CHAR;

static bool is_colision(game_t *tetris, int x, int y)
{
    if (tetris->ppiece.coord.y + y >= tetris->conf.map_height)
        return true;
    if (tetris->ppiece.piece->mtx[y][x] == PIECE_CHAR)
        if(tetris->map[tetris->ppiece.coord.y + y]
            [tetris->ppiece.coord.x + x - 1] != BACKG_CHAR)
            return true;
    return false;
}

bool colision(game_t *tetris)
{
    bool exit = false;

    for (int y = 0; y < tetris->ppiece.piece->height && !exit; y++)
        for (int x = 0; x < tetris->ppiece.piece->width && !exit; x++)
            exit = is_colision(tetris, x, y);
    return exit;
}
static void print_in_map(game_t *tetris)
{
    int p_x = tetris->ppiece.coord.x;
    int p_y = tetris->ppiece.coord.y;

    for (int y = 0; y < tetris->ppiece.piece->height; y++)
        for (int x = 0; x < tetris->ppiece.piece->width; x++)
            tetris->map[p_y + y - 1] [p_x + x - 1] =
            (tetris->ppiece.piece->mtx[y][x] == PIECE_CHAR) ?
            tetris->ppiece.piece->color : tetris->map[p_y + y - 1] [p_x + x - 1];
}

void my_colision(game_t *tetris)
{
    if (colision(tetris)) {
        print_in_map(tetris);
        tetris->ppiece.coord.y = 0;
    }
}