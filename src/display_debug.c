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
    my_printf("%s : %s\n", str, key);
    free(key);
    return EXIT_SUCCESS;
}

static int key_display(config_t config)
{
    char *name[] = {"Key Left", "Key Right", "Key Turn", "Key Drop",
    "Key Quit", "Key Pause"};

    if (key_manage(name[0], get_key(config.key_left)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[1], get_key(config.key_right)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[2], get_key(config.key_turn)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[3], get_key(config.key_drop)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[4], get_key(config.key_quit)) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[5], get_key(config.key_pause)) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static void display_tetriminos(game_t tetris)
{
    my_printf("Tetriminos : %i\n", tetris.pieces.size);
    for (int i = 0; i < tetris.pieces.size; i++) {
        if (!tetris.pieces.pc[i].mtx)
            my_printf("Tetriminos : Name %s : Error", PIECE(i).name);
        else {
            my_printf("Tetriminos : Name %s : Size %i*%i : Color %i : \n",
            PIECE(i).name, PIECE(i).width, PIECE(i).height, PIECE(i).color);
            for (int u = 0; u < PIECE(i).height; u++)
                my_printf("%s\n", PIECE(i).mtx[u]);
        }
    }
}

int show_debug_screen(game_t tetris)
{
    if (key_display(tetris.conf) == EXIT_ERROR)
        return EXIT_ERROR;
    if (tetris.conf.hide_next_tetrimino)
        my_printf("Next : yes\n");
    else
        my_printf("Next : no\n");
    my_printf("Level : %i\n", tetris.conf.start_level);
    my_printf("Size : %i*%i\n", tetris.conf.map_width, tetris.conf.map_height);
    display_tetriminos(tetris);
    my_printf("Press any key to start Tetris\n");
    return 0;
}
