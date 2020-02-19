##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c								\
		src/scene_menu.c						\
		src/sprite_sheet/background_menu.c		\
		src/sprite_sheet/dg_cpt_spritesheet.c	\
		src/text/cpt_text.c						\
		src/text/text_menu.c					\
		src/button/cpt_button.c					\
		src/cpt_scale.c							\
		src/cpt_action.c						\
		src/button/sys_button.c					\
		src/sprite_sheet/cpt_box_collider.c		\
		src/sound/cpt_sound.c					\
		src/sound/ent_music.c					\

NAME	=	my_defender

DEBUG	=	defender.d

all:	$(NAME)	## Build the project

$(NAME):
	@make -C dragon/
	@$(CC) -o $(NAME) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(SRC) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"

debug: ## Lunch the debug
	@make -C dragon/
	@$(CC) -g3 -o $(DEBUG) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(DEBUG) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(SRC) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources debug ▄▀▄▀▄▀\e[0m\n"

clean: ## Clean the useless file
	@make clean -C dragon/

fclean:	clean ## Clean the project
	@make fclean -C dragon/
	@rm -f $(NAME)
	@rm -f $(DEBUG)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(DEBUG) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"


re:	fclean all ## Clean then compile

valgrind: fclean debug ## Launch valgrind
	@valgrind --show-leak-kinds=all --track-origins=yes ./$(DEBUG)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help