/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T10:33:20+01:00 | Author: simon
*/

#include "tetris.h"

const char *PATH_TETRIMINOS = "./tetriminos/";
const char *TETRIMINO_CHAR = "* ";

// WINDOW

const int TITLE_HEIGHT = 5;
const int TITLE_WIDTH = 56;

const int PANEL_HEIGHT = 20;
const int PANEL_WIDTH = 20;


// PROGRAM options

const char *OPTIONS = "L:l:r:t:d:p:q:wD";

const struct option LONG_OPTIONS[] = {
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'p'},
    {"key-pause", required_argument, NULL, 'q'},
    {"map-size", required_argument, NULL, 's'},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {NULL, 0, NULL, 0}
};

// MAP

const int MAP_ROW_WIDTH = 1;
const int MAP_ROW_HEIGHT = 1;

// DISPLAYED CHAR

const char PIECE_CHAR = '*';
const char BACKG_CHAR = ' ';

const char MAP_EDGE[3] =
{
    '|',
    '-',
    '+'
};
const char PANEL_EDGE[3] =
{
    '-',
    '|',
    '.'
};
const int EDGE_UP = 0;
const int EDGE_SIDE = 1;
const int EDGE_CORNER = 2;

// DEFAULT CONFIG

const int INIT_START_LEVEL = 1;
const int INIT_KEY_LEFT = KEY_LEFT;
const int INIT_KEY_RIGHT = KEY_RIGHT;
const int INIT_KEY_TURN = KEY_UP;
const int INIT_KEY_DROP = KEY_DOWN;
const int INIT_KEY_QUIT = 'q';
const int INIT_KEY_PAUSE = ' ';
const int INIT_MAP_HEIGHT = 10;
const int INIT_MAP_WIDTH = 20;
const bool INIT_DEBUG_MODE = false;
const bool INIT_HIDE_NEXT_TERMI = false;

// Keyboard

const key_s KEY_SPEC[] = {
    {KEY_UP,        "Up arrow"        },
    {KEY_DOWN,      "Down arrow"      },
    {KEY_LEFT,      "Left arrow"      },
    {KEY_RIGHT,     "Right arrow"     },
    {KEY_HOME,      "Home"            },
    {KEY_END,       "End"             },
    {KEY_BACKSPACE, "Backspace"       },
    {KEY_IC,        "Insert"          },
    {KEY_DC,        "Delete"          },
    {KEY_NPAGE,     "Page down"       },
    {KEY_PPAGE,     "Page up"         },
    {' ',           "(space)"         },
};

//

const char *TITLE1 =
    "_______  ______  _    __ _______  ______  _____  ______ \n"
    "  | |   | |     | |  / /   | |   | |  | \\  | |  / |     \n"
    "  | |   | |---- | |-< <    | |   | |__| |  | |  '------.\n"
    "  |_|   |_|____ |_|  \\_\\   |_|   |_|  \\_\\ _|_|_  ____|_/\n";

const char *TITLE2 =
    " _____ ___ _  _______ ___ _   __\n"
    "|_   _| __| |/ /_   _| _ \\ |/' _/\n"
    "  | | | _||   <  | | | v / |`._`.\n"
    "  |_| |___|_|\\_\\ |_| |_|_\\_||___/\n";

const char *MYTERM = "TERM=";

const int NB_KEY = 4;

const char *SPECIAL_KEYS[] = {  "kcub1",
                                "kcuf1",
                                "kcuu1",
                                "kcud1"
                            };