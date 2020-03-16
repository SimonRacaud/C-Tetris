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
		$(DSRC)game/game_play.c							\
		$(DSRC)game/display/display.c					\
		$(DSRC)game/display/display_menu.c				\
		$(DSRC)game/display/display_board.c				\
		$(DSRC)game/input/catch_input.c					\
		$(DSRC)game/input/get_input.c					\
		$(DSRC)game/input/input_apply.c					\
		$(DSRC)game/map/map_eval.c						\
		$(DSRC)prepare/game_init.c						\
		$(DSRC)prepare/get_config.c						\
		$(DSRC)prepare/config_init.c					\
		$(DSRC)prepare/config/config_apply_options.c	\
		$(DSRC)prepare/load_tetriminos.c				\
		$(DSRC)prepare/load_piece.c						\
		$(DSRC)prepare/pieces_destroy.c				\
		$(DSRC)prepare/game_destroy.c					\
		$(DSRC)prepare/sort_tetriminos.c				\
		$(DSRC)prepare/get_special_key.c				\
		$(DSRC)piece/rotate.c							\
		$(DSRC)piece/write_on_map.c						\
		$(DSRC)display_debug.c							\
		$(DSRC)colision.c							\
		$(DSRC)game/display/display_player_pieces.c		\

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
