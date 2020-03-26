##
## EPITECH PROJECT, 2020
## PSU_tetris_2019
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c									\
		$(DSRC)constant.c								\
		$(DSRC)usage.c									\
		$(DSRC)tetris.c									\
		$(DSRC)misc/tools.c								\
		$(DSRC)misc/tools_file.c						\
		$(DSRC)misc/linked_file_list.c					\
		$(DSRC)window/window_create_destroy.c			\
		$(DSRC)attribute_access/level.c					\
		$(DSRC)attribute_access/score.c					\
		$(DSRC)attribute_access/line.c					\
		$(DSRC)game/game_play.c							\
		$(DSRC)game/check_term_size.c					\
		$(DSRC)game/set_game_speed.c					\
		$(DSRC)game/display/display.c					\
		$(DSRC)game/display/display_menu.c				\
		$(DSRC)game/display/display_board.c				\
		$(DSRC)game/display/display_player_piece.c		\
		$(DSRC)game/display/display_pieces.c			\
		$(DSRC)game/display/color_init.c				\
		$(DSRC)game/display/display_end_menu.c			\
		$(DSRC)game/display/pause.c						\
		$(DSRC)game/dup_tetrimino_t.c					\
		$(DSRC)game/input/catch_input.c					\
		$(DSRC)game/input/get_input.c					\
		$(DSRC)game/input/input_apply.c					\
		$(DSRC)game/map/map_eval.c						\
		$(DSRC)prepare/game_init.c						\
		$(DSRC)prepare/get_config.c						\
		$(DSRC)prepare/config_init.c					\
		$(DSRC)prepare/config/config_apply_options.c	\
		$(DSRC)prepare/config/check_argv.c				\
		$(DSRC)prepare/config/check_for_option_name.c	\
		$(DSRC)prepare/load_tetriminos.c				\
		$(DSRC)prepare/load_piece.c						\
		$(DSRC)prepare/load_piece_check.c				\
		$(DSRC)prepare/pieces_destroy.c					\
		$(DSRC)prepare/game_destroy.c					\
		$(DSRC)prepare/clean_piece.c					\
		$(DSRC)prepare/sort_tetriminos.c				\
		$(DSRC)prepare/get_special_key.c				\
		$(DSRC)piece/rotate.c							\
		$(DSRC)piece/write_on_map.c						\
		$(DSRC)piece/set_player_piece.c					\
		$(DSRC)piece/set_next_piece.c					\
		$(DSRC)piece/piece_have_collision.c				\
		$(DSRC)piece/piece_is_in_map_range.c			\
		$(DSRC)piece/piece_move.c						\
		$(DSRC)piece/drop.c								\
		$(DSRC)debug_mode/display_debug.c				\
		$(DSRC)debug_mode/canonical_mode.c				\
		$(DSRC)debug_mode/count_tetriminos.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS	+= -Wall -Wextra -W -I./include -g -lncurses

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses -L./lib/my -lmy

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#gcc -o $(NAME) $(SRC_UT) -I./include -L./lib/my -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re
