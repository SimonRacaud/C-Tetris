/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include <curses.h>
#include "game_t.h"
#include "debug.h"
#include "my.h"

extern const key_s KEY_SPEC[];

static char *get_key(int val)
{
    char *key;

    if (val >= 32 && val <= 125) {
        key = malloc(sizeof(char) * 2);
        if (!key)
            return NULL;
        key[1] = '\0';
        key[0] = val;
    }
    else {
        for (int i = 0; i < 23; i++) {
            if (KEY_SPEC[i].code == val)
                return my_strdup(KEY_SPEC[i].cqfd);
        }
        return NULL;
    }
    return key;
}

static int key_manage(char *str, char *key)
{
    if (!key)
        return EXIT_ERROR;
    printw("%s : %s\n", str, key);
    free(key);
    return EXIT_SUCCESS;
}

static int key_display(config_t *config)
{
    char *name[] = {"Key Left", "Key Right", "Key Turn", "Key Drop",
    "Key Quit", "Key Pause"};

    if (key_manage(name[0], get_key(config->key_left)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[1], get_key(config->key_right)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[2], get_key(config->key_turn)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[3], get_key(config->key_drop)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[4], get_key(config->key_quit)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[5], get_key(config->key_pause)) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static void display_tetriminos(game_t *tetris)
{
    printw("Tetriminos : %i\n", tetris->pieces.size);
    for (int i = 0; i < tetris->pieces.size; i++) {
        if (!tetris->pieces.pc[i].mtx)
            printw("Tetriminos : Name %s : Error\n", PIECE(i).name);
        else {
            printw("Tetriminos : Name %s : Size %i*%i : Color %i : \n",
            PIECE(i).name, PIECE(i).width, PIECE(i).height, PIECE(i).color);
            for (int u = 0; u < PIECE(i).height; u++)
                printw("%s\n", PIECE(i).mtx[u]);
        }
    }
}

int show_debug_screen(game_t *tetris)
{
    config_t *config = &tetris->conf;

    initscr();
    printw("*** DEBUG MODE ***\n");
    if (key_display(config) == EXIT_ERROR)
        return EXIT_ERROR;
    if (config->hide_next_tetrimino)
        printw("Next : Yes\n");
    else
        printw("Next : No\n");
    printw("Level : %i\n", config->start_level);
    printw("Size : %i*%i\n", config->map_width, config->map_height);
    display_tetriminos(tetris);
    printw("Press any key to start Tetris\n");
    refresh();
    getch();
    endwin();
    return EXIT_SUCCESS;
}
