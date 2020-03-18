/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-18T10:11:35+01:00 | Author: simon
*/

#include "tetris.h"

void display_end_menu(game_t *tetris)
{
    if (tetris->score > tetris->high_score) {
        tetris->high_score = tetris->score;
    }
    timeout(-1);
    erase();
    printw("%s\n\n", "GAME OVER !");
    printw("Score: %d\n", tetris->score);
    printw("High Score: %d\n", tetris->high_score);
    printw("Level: %d\n", tetris->level);
    printw("Lines: %d\n\n", tetris->line);
    printw("Press any key to quit Tetris\n");
    getch();
}
