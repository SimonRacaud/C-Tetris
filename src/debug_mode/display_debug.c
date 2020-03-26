/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "game_t.h"
#include "debug.h"
#include "my.h"

static int key_manage(char *str, char *key)
{
    if (key && key[0] == '\e') {
        my_printf("%s : ^E%s\n", str, key + 1);
    } else if (key && key[0] == ' ') {
        my_printf("%s : (space)\n", str);
    } else
        my_printf("%s : %s\n", str, key);
    return EXIT_SUCCESS;
}

static int key_display(config_t *config)
{
    char *name[] = {"Key Left", "Key Right", "Key Turn", "Key Drop",
    "Key Quit", "Key Pause"};

    if (key_manage(name[0], config->key_ptr[LEFT_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[1], config->key_ptr[RIGHT_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[2], config->key_ptr[TURN_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[3], config->key_ptr[DROP_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[4], config->key_ptr[QUIT_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[5], config->key_ptr[PAUSE_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static void display_tetriminos_content(tetrimino_t *piece)
{
    my_printf("Tetriminos : Name %s : Size %i*%i : Color %i :\n",
    piece->name, piece->width, piece->height, piece->color);
    for (int u = 0; u < piece->height; u++)
        my_printf("%s\n", piece->mtx[u]);
}

static void display_tetriminos(game_t *tetris)
{
    my_printf("Tetriminos : %i\n", count_tetriminos(&tetris->pieces));
    for (int i = 0; i < tetris->pieces.size; i++) {
        if (!tetris->pieces.pc[i].mtx && tetris->pieces.pc[i].name[0] != '\0')
            my_printf("Tetriminos : Name %s : Error\n", PIECE(i).name);
        else if (tetris->pieces.pc[i].mtx) {
            display_tetriminos_content(&tetris->pieces.pc[i]);
        }
    }
}

int show_debug_screen(game_t *tetris)
{
    char buffer[1];
    config_t *config = &tetris->conf;

    my_putstr("*** DEBUG MODE ***\n");
    if (key_display(config) == EXIT_ERROR)
        return EXIT_ERROR;
    if (!config->hide_next_tetrimino)
        my_putstr("Next : Yes\n");
    else
        my_putstr("Next : No\n");
    my_printf("Level : %i\n", config->start_level);
    my_printf("Size : %i*%i\n", config->map_width, config->map_height);
    display_tetriminos(tetris);
    my_putstr("Press any key to start Tetris\n");
    canonical_mode_select(true);
    read(0, buffer, 1);
    canonical_mode_select(false);
    return EXIT_SUCCESS;
}
