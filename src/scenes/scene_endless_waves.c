/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** scene_endless_waves
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void change_stat(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("game");
    dg_entity_t **sub = (dg_entity_t **)dg_entity_get_component(entity, "subentity");
    dg_entity_t *sub_button = 0;

    dg_scene_add_ent(scene, ent_music("./sound/click.ogg"));
    if (!sub)
        return;
    sub_button = ent_button((sfVector2f){0, 0}, 100, "lol", NULL);
    sub = &sub_button;
    dg_scene_add_ent(scene, *sub);
}

static sfVector2f *game_path(void)
{
    sfVector2f *path = malloc(sizeof(sfVector2f) * 5);

    path[0] = (sfVector2f) {500, 500};
    path[1] = (sfVector2f) {1000, 500};
    path[2] = (sfVector2f) {1200, 300};
    path[3] = (sfVector2f) {2000, 2000};
    path[4] = (sfVector2f) {-1, -1};
    return path;
}

dg_scene_t *scene_endless_waves(void)
{
    dg_scene_t *scene = dg_scene_create("game");
    dg_scene_t *scene_escape = 0;

    scene_escape->display = 1;
    scene_escape = dg_scene_manager_get_scene("escape_menu");
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, ent_music("./sound/main_theme.ogg"));
    dg_scene_add_ent(scene, ent_slot((sfVector2f){0, 0},
        (sfVector2f){0.5, 0.5}, &change_stat));
    dg_scene_add_ent(scene, ent_sprite(6, 1, 0, 0));
    dg_scene_add_ent(scene, ent_monster((sfVector2f) {100, 100}, 0));
    dg_scene_add_ent(scene, ent_path(game_path()));
    dg_scene_add_sys(scene, dg_system_create(&sys_slot, 0));
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_escape, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_follow_path, 0));
    return scene;
}