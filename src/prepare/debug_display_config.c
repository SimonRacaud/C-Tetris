/*
** EPITECH PROJECT, 2020
** PROJECT_NAME
** File description:
** Created: 2020-03-09T15:42:54+01:00 | Author: simon
*/

 #include "tetris.h"

 void debug_display_config(config_t *config)
 {
     my_printf("start level: %d \n", config->start_level);
     my_printf("key left: %d \n", config->my_key_left);
     my_printf("key right: %d \n", config->my_key_right);
     my_printf("key turn: %d \n", config->my_key_turn);
     my_printf("key drop: %d \n", config->my_key_drop);
     my_printf("key quit: %d \n", config->my_key_quit);
     my_printf("key pause: %d \n", config->my_key_pause);
     my_printf("Map height: %d \n", config->map_height);
     my_printf("Map width: %d \n", config->map_width);
     my_printf("Hide next tetrimino: %d \n", config->hide_next_tetrimino);
     my_printf("Debug mode: %d \n", config->debug_mode);
     my_putstr("------------------------------------\n");
 }
