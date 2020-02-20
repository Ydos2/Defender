/*
** EPITECH PROJECT, 2020
** scene_menu
** File description:
** scene_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void go_to_map(dg_window_t *w)
{
    dg_scene_t *old_scene = dg_scene_manager_get_scene("main_menu");
    dg_scene_t *new_scene = 0;

    dg_scene_manager_add_scene(scene_game());
    new_scene = dg_scene_manager_get_scene("game");
    old_scene->run = 0;
    old_scene->display = 0;
    new_scene->run = 1;
    new_scene->display = 1;
}

static void go_to_quit(dg_window_t *w)
{
    w->quit = 1;
}

dg_scene_t *scene_main_menu(void)
{
    dg_scene_t *scene = dg_scene_create("main_menu");

    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){800, 500}, "          Play", &go_to_map));
    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){800, 700}, "          Quit", &go_to_quit));
    dg_scene_add_ent(scene, ent_music("./sound/menu_song.ogg"));
    dg_scene_add_ent(scene, ent_sprite(0));
    dg_scene_add_ent(scene, ent_text(800, 200, 200, "Menu"));
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    scene->run = 1;
    scene->display = 1;
    return scene;
}
