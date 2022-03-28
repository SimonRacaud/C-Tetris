/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "tetris.h"

extern char *PAUSE;

void my_pause(void)
{
    erase();
    mvprintw(0, 0, "%s", PAUSE);
    mvprintw(8, 0, "Press space key to return at game\n");
    while (getch() == ERR);
}