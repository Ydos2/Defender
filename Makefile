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
			src/scenes/scene_how_to_play.c		\
			src/scenes/scene_lose.c				\

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
			src/components/cpt_subentity.c		\
			src/components/cpt_game_data.c		\
			src/components/cpt_build_id.c		\
			src/components/cpt_script.c			\
			src/components/cpt_path_bullet.c	\
			src/components/cpt_color.c			\

SRC_ENT =	src/entities/ent_music.c			\
			src/entities/ent_sprite.c			\
			src/entities/ent_text.c				\
			src/entities/ent_button.c			\
			src/entities/ent_monster.c			\
			src/entities/ent_path.c				\
			src/entities/ent_slot.c				\
			src/entities/ent_map.c				\
			src/entities/ent_game_data.c		\
			src/entities/ent_tower.c			\
			src/entities/ent_score.c			\
			src/entities/ent_build_menu.c		\
			src/entities/ent_bullet.c			\
			src/entities/ent_waves.c			\
			src/entities/ent_castle.c			\
			src/entities/ent_slot_delete.c		\
			src/entities/ent_slot_upgrade.c		\
			src/entities/ent_bomb.c				\

SRC_SYS =	src/systems/sys_render.c			\
			src/systems/sys_display_text.c		\
			src/systems/sys_button.c			\
			src/systems/sys_escape.c			\
			src/systems/sys_follow_path.c		\
			src/systems/sys_slot.c				\
			src/systems/sys_camera.c			\
			src/systems/sys_create_tower.c		\
			src/systems/sys_tower_spawn_range.c	\
			src/systems/sys_script.c			\
			src/systems/sys_tower_attack.c		\
			src/systems/sys_lose.c				\
			src/systems/sys_path_bullet.c		\

SRC_MNT =	src/monsters/monster_basic.c		\

SRC_TOW =	src/towers/tower_basic.c			\

SRC_INI =	src/init/init_img.c					\
			src/init/set_build_id.c				\

SRC_SPT =	src/scripts/script_score.c			\
			src/scripts/script_attack_tower.c	\
			src/scripts/script_monster.c		\
			src/scripts/script_build_menu.c		\
			src/scripts/script_build_buttons.c	\
			src/scripts/script_bullet.c			\
			src/scripts/script_wave.c			\
			src/scripts/script_castle.c			\
			src/scripts/script_tower_menu.c		\
			src/scripts/script_delete_buttons.c	\
			src/scripts/script_upgrade_buttons.c\
			src/scripts/tower_spe_attack.c		\
			src/scripts/script_boum.c			\

SRC_LIB =	lib/get_next_line.c			\
			lib/my_putarray.c			\
			lib/my_strcpy.c				\
			lib/str_to_array.c			\
			lib/tools_function.c		\
			lib/transform_character.c	\
			lib/my_strdup.c				\
			lib/itoa.c					\
			lib/my_revstr.c				\
			lib/nblen.c					\

SRC	=	$(SRC_OTH)	\
		$(SRC_SCN)	\
		$(SRC_CPT)	\
		$(SRC_ENT)	\
		$(SRC_SYS)	\
		$(SRC_MNT)	\
		$(SRC_INI)	\
		$(SRC_TOW)	\
		$(SRC_SPT)	\

LIB	=	$(SRC_LIB)	\

NAME	=	my_defender

DEBUG	=	defender.d

all:	$(NAME)	## Build the project

$(NAME):
	@make -C dragon/
	@$(CC) -g3 -o $(NAME) $(SRC) $(LIB) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(SRC) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@printf "[\e[1;35m-Link Lib-\e[0m] % 43s\n" $(LIB) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling lib ▄▀▄▀▄▀\e[0m\n"

debug: ## Lunch the debug
	@make -C dragon/
	@$(CC) -g3 -o $(DEBUG) $(SRC) $(LIB) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(DEBUG) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(SRC) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(LIB) | tr ' ' '.'
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