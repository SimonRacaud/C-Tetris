/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T10:33:20+01:00 | Author: simon
*/

#include <getopt.h>
#include <stdlib.h>
#include <stdbool.h>

const char *PATH_TETRIMINOS = "./tetriminos/";
const char *TETRIMINO_CHAR = "* ";

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
    '-',
    '|',
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

static const key_s KEY_SPEC[] = {
    { KEY_UP,        "Up arrow"        },
    { KEY_DOWN,      "Down arrow"      },
    { KEY_LEFT,      "Left arrow"      },
    { KEY_RIGHT,     "Right arrow"     },
    { KEY_HOME,      "Home"            },
    { KEY_END,       "End"             },
    { KEY_BACKSPACE, "Backspace"       },
    { KEY_IC,        "Insert"          },
    { KEY_DC,        "Delete"          },
    { KEY_NPAGE,     "Page down"       },
    { KEY_PPAGE,     "Page up"         },
    { KEY_F(1),      "Function key 1"  },
    { KEY_F(2),      "Function key 2"  },
    { KEY_F(3),      "Function key 3"  },
    { KEY_F(4),      "Function key 4"  },
    { KEY_F(5),      "Function key 5"  },
    { KEY_F(6),      "Function key 6"  },
    { KEY_F(7),      "Function key 7"  },
    { KEY_F(8),      "Function key 8"  },
    { KEY_F(9),      "Function key 9"  },
    { KEY_F(10),     "Function key 10" },
    { KEY_F(11),     "Function key 11" },
    { KEY_F(12),     "Function key 12" }
};
