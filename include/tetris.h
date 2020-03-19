/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef TETRIS_H
#define TETRIS_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <ncurses.h>
#include <time.h>
#include "my.h"
#include "game_t.h"
#include "debug.h"
#include "window.h"

#define EXIT_ERROR 84

enum piece_move_sens {
    PIECE_SENS_H,
    PIECE_SENS_V_LEFT,
    PIECE_SENS_V_RIGHT
};

typedef struct file_list {
    struct file_list *next;
    char *filename;
} file_list_t;

// Base Functions

int usage(int status, const char *app_name);
int tetris(int argc, char **argv, char **env);

// GAME
int game_play(game_t *tetris);
void color_init(void);
void set_game_speed(game_t *tetris);
void increase_level(game_t *tetris);
void update_high_score(game_t *tetris);
void increase_score(game_t *tetris, int coef);
void increase_line(game_t *tetris);

// MAP
void map_eval(game_t *game);
int write_on_map(game_t *tetris);

// Tools Functions
bool have_str_in_array(char **array, int size, const char *str);
int my_get_check_nbr(char *str, int *nbr, const char *ignore);
bool have_char_in_string(char c, const char *str);
char *merge_path_filename(const char *path, const char *filename);
char *get_filename_without_ext(const char *filename);
bool have_only_correct_char_in_str(const char *str, const char *correct_chars);
int get_key_code(char *str, char *key);

// Destroy
void pieces_destroy(pieces_t *pieces);
void tetrimino_destroy(tetrimino_t *tet);
void game_destroy(game_t *tetris);

// Prepare and Init
int game_init(game_t *tetris, char **argv, int argc, char **env);
int get_config(config_t *conf, char **argv, int argc, char **env);
void config_init_default(config_t *conf);
void config_init_spec_key(config_t *conf);
int load_tetriminos(pieces_t *pieces);
int load_piece(tetrimino_t *tetrminimo, char *filename);
int sort_tetriminos(tetrimino_t *pc, int size);
char **get_special_key(char **env);

int apply_option_key_piece(config_t *conf, char index);
int apply_option_key_menu(config_t *conf, char index);
int apply_option_misc(config_t *conf, char index);
int apply_option_map_size(config_t *conf, char index);

// Lisked file list
void file_list_destroy(file_list_t *list);
int file_list_add(file_list_t **list, const char *filename);

// Debug Mode function
int show_debug_screen(game_t *tetris);
void canonical_mode_select(bool enable);

// PIECE MANAGEMENT
int rotate(tetrimino_t *piece);
int set_player_piece(tetrimino_t *next_piece, player_piece_t *ppiece,
game_t *game);
int set_next_piece(game_t *game);
bool piece_move(game_t *tetris, enum piece_move_sens sens);
bool piece_have_collision(game_t *tetris);
bool piece_is_in_map_range(game_t *tetris, player_piece_t *piece);
void drop_piece(game_t *tetris);

// Display
int display(game_t *tetris);
int display_menu(game_t *tetris);
void display_end_menu(game_t *tetris);
int display_board(game_t *tetris);
void display_pieces(game_t *tetris);
void display_player_piece(game_t *tetris, window_t *board);
void my_colision(game_t *tetris);
void color_init(void);
void my_pause(void);

// INPUT
int catch_input(game_t *tetris);
bool get_input(char *in, int size);
int input_apply(char *input, int size, game_t *tetris);

#endif
