/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T10:33:20+01:00 | Author: simon
*/

// MAP

const int MAP_ROW_WIDTH = 1;
const int MAP_ROW_HEIGHT = 1;

// DISPLAYED CHAR

const char PIECE_CHAR = '*';
const char BACKG_CHAR = ' ';

const char MAP_EDGE[3] =
{
    '-',
    '|',
    '+'
}
const char PANEL_EDGE[3] =
{
    '-',
    '|',
    '.'
}
const int EDGE_UP = 0;
const int EDGE_SIDE = 1;
const int EDGE_CORNER = 2;

// DEFAULT CONFIG

const int INIT_START_LEVEL = 1;
const int INIT_KEY_LEFT = 0;
const int INIT_KEY_RIGHT = 0;
const int INIT_KEY_TURN = 0;
const int INIT_KEY_DROP = 0;
const int INIT_KEY_QUIT = 0;
const int INIT_KEY_PAUSE = 0;
const int INIT_MAP_HEIGHT = 0;
const int INIT_MAP_WIDTH = 0;
const bool INIT_DEBUG_MODE = false;
const bool INIT_HIDE_NEXT_TERMI = false;
