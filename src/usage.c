/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-09T08:33:18+01:00 | Author: simon
*/

#include "tetris.h"

static const char *USAGE =
"Usage:\t./tetris [options]\n"
"Options:\n"
"\t--help\t\t\tDisplay this help\n"
"\t-L --level={num}\tStart Tetris at level num (def: 1)\n"
"\t-l --key-left={K}\t"
"Move the tetrimino LEFT using the K key (def: left arrow)\n"
"\t-r --key-right={K}\t"
"Move the tetrimino RIGHT using the K key (def: right arrow)\n"
"\t-t --key-turn={K}\t"
"TURN the tetrimino clockwise 90d using the K key (def: toparrow)\n"
"\t-d --key-drop={K}\tDROP the tetrimino using the K key (def: down arrow)\n"
"\t-q --key-quit={K}\tQUIT the game using the K key (def: ‘q’ key)\n"
"\t-p --key-pause={K}\t"
"PAUSE/RESTART the game using the K key (def: space bar)\n"
"\t--map-size={row,col}\t"
"Set the numbers of rows and columns of the map (def: 20,10)\n"
"\t-w --without-next\tHide next tetrimino (def: false)\n"
"\t-D --debug\t\tDebug mode (def: false)\n";

int usage(int status)
{
    my_putstr("\033[1m\033[32m");
    my_putstr(USAGE);
    my_putstr("\033[0m");
    return status;
}
