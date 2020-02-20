/*
** EPITECH PROJECT, 2020
** scene_menu
** File description:
** scene_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_scene_t *scene_game(void)
{
    dg_scene_t *scene = dg_scene_create("game");
    dg_scene_t *scene_escape = 0;

    scene_escape = dg_scene_manager_get_scene("escape_menu");
    dg_scene_add_ent(scene, ent_music("./sound/main_theme.ogg"));
    dg_scene_add_ent(scene, ent_sprite(2, 1, 0, 0));
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_escape, 1));
    return scene;
}