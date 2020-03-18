/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "tetris.h"

extern char PIECE_CHAR;
extern char BACKG_CHAR;

static bool is_collision(game_t *tetris, int x, int y)
{
    if (tetris->ppiece.coord.y + y >= tetris->conf.map_height)
        return true;
    if (tetris->ppiece.piece->mtx[y][x] == PIECE_CHAR)
        if(tetris->map[tetris->ppiece.coord.y + y]
            [tetris->ppiece.coord.x + x - 1] != BACKG_CHAR)
            return true;
    return false;
}

static bool collision(game_t *tetris)
{
    bool exit = false;

    for (int y = 0; y < tetris->ppiece.piece->height && !exit; y++) {
        for (int x = 0; x < tetris->ppiece.piece->width && !exit; x++) {
            exit = is_collision(tetris, x, y);
        }
    }
    return exit;
}

void drop_piece(game_t *tetris)
{
    while(!collision(tetris)) {
        tetris->ppiece.coord.y++;
    }
    tetris->ppiece.coord.y--;
}