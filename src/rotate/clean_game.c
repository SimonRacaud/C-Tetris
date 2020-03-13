/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include <stdbool.h>
#include "tetris.h"

extern char BACKG_CHAR;

static void break_line(game_t *game, int y)
{
    char *temp = game.map[y];

    for (int x = 0; x < game.conf.map_width; game.map[y][x] = BACKG_CHAR, x++);
    for (int move = y; move > 0; move--)
        game.map[move] = game.map[move - 1]
    game.map[0] = temp;
}

static bool is_full_line(char *line, int size)
{
    for (int x = 0; x < size; x++)
        if (line[x] == BACKG_CHAR)
            return false;
    return true;
}

void clean_lines_map(game_t *game)
{
    for (int y = 0, y < game.conf.map_height; y++)
        if (is_full_line(game.map[y], game.conf.map_width))

}