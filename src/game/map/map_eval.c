/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-16T11:34:58+01:00 | Author: sullivan, simon
*/

#include "tetris.h"

extern char BACKG_CHAR;

static void remove_line(game_t *game, int y)
{
    char *temp = game->map[y];

    for (int x = 0; x < game->conf.map_width; x++)
        game->map[y][x] = BACKG_CHAR;
    for (int move = y; move > 0; move--)
        game->map[move] = game->map[move - 1];
    game->map[0] = temp;
}

static bool is_full_line(char *line, int size)
{
    for (int x = 0; x < size; x++)
        if (line[x] == BACKG_CHAR)
            return false;
    return true;
}

void map_eval(game_t *game)
{
    for (int y = 0; y < game->conf.map_height; y++) {
        if (is_full_line(game->map[y], game->conf.map_width)) {
            remove_line(game, y);
            game->line++;
        }
    }
    if (write_on_map(game) == EXIT_FAILURE) {
        game->status = FAIL;
    }
}
