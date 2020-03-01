##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC_OTH = 	src/main.c							\

SRC_SCN =	src/scenes/scene_main_menu.c		\
			src/scenes/scene_game.c				\
			src/scenes/scene_escape_menu.c		\

SRC_CPT =	src/components/cpt_action.c			\
			src/components/cpt_text.c			\
			src/components/cpt_scale.c			\
			src/components/cpt_box_collider.c	\
			src/components/cpt_spritesheet.c	\
			src/components/cpt_sound.c			\
			src/components/cpt_tag.c			\
			src/components/cpt_path.c			\
			src/components/cpt_path_follower.c	\
			src/components/cpt_slot.c			\

SRC_ENT =	src/entities/ent_music.c			\
			src/entities/ent_sprite.c			\
			src/entities/ent_text.c				\
			src/entities/ent_button.c			\
			src/entities/ent_monster.c			\
			src/entities/ent_path.c				\
			src/entities/ent_slot.c				\

SRC_SYS =	src/systems/sys_render.c			\
			src/systems/sys_display_text.c		\
			src/systems/sys_button.c			\
			src/systems/sys_escape.c			\
			src/systems/sys_follow_path.c		\
			src/systems/sys_slot.c				\

SRC_MNT =	src/monsters/monster_basic.c		\

SRC_INI =	src/init/init_img.c					\

SRC	=	$(SRC_OTH)	\
		$(SRC_SCN)	\
		$(SRC_CPT)	\
		$(SRC_ENT)	\
		$(SRC_SYS)	\
		$(SRC_MNT)	\
		$(SRC_INI)	\

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