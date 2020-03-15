/*
** EPITECH PROJECT, 2020
** scene_lose
** File description:
** scene_lose
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

static void go_to_menu(dg_window_t *w)
{
    dg_scene_t *new_scene = 0;

    dg_scene_manager_add_scene(scene_main_menu());
    new_scene = dg_scene_manager_get_scene("main_menu");
    new_scene->run = 1;
    new_scene->display = 1;
    dg_scene_manager_remove("scoreboard");
}

static void go_to_game(dg_window_t *w)
{
    dg_scene_t *new_scene = 0;

    dg_scene_manager_add_scene(scene_game());
    dg_scene_manager_add_scene(scene_escape_menu());
    new_scene = dg_scene_manager_get_scene("game");
    new_scene->run = 1;
    new_scene->display = 1;
    dg_scene_manager_remove("scoreboard");
}

static void text_add_ent(dg_scene_t *scene)
{
    dg_entity_t *gd = ent_game_data();
    game_data_t *game_data = dg_entity_get_component(gd, "game_data");

    dg_scene_add_ent(scene, ent_text(200, 100, 200, "Score Board"));
    dg_scene_add_ent(scene, ent_score((sfVector2f){200, 700},
        100, "Your score : ", (&game_data->wave)));
}

dg_scene_t *scene_lose(void)
{
    dg_scene_t *scene = dg_scene_create("scoreboard");

    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){1100, 700}, 100, "Menu", &go_to_menu));
    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){1050, 850}, 100, "Restart", &go_to_game));
    dg_scene_add_ent(scene, ent_music("./sound/lose.ogg"));
    dg_scene_add_ent(scene, ent_music("./sound/menu_song.ogg"));
    dg_scene_add_ent(scene, ent_sprite(0, 1, 0, 0));
    text_add_ent(scene);
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    scene->run = 1;
    scene->display = 1;
    return scene;
}