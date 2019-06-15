##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/main.c	\
		src/setup.c	\
		src/setup_menu.c	\
		src/setup_levels_menu.c	\
		src/setup_lvlend.c	\
		src/scenes_loader.c	\
		src/level_loader.c	\
		src/custom_event.c	\
		src/menu.c	\
		src/menu_levels.c	\
		src/ingame.c	\
		src/level_end.c	\
		src/birds.c	\
		src/update_birds.c	\
		src/set_y_position.c	\
		src/life.c	\
		src/help.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lm

NAME	=	my_hunter

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)
	rm -f $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)
	rm -f vgcore.*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
