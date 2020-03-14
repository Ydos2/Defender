/*
** EPITECH PROJECT, 2020
** scene_menu
** File description:
** scene_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void change_stat(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("game");
    dg_component_t *sub = (dg_component_t *)
        dg_entity_get_full_component(entity, "subentity");
    dg_entity_t *sub_button = 0;

    if (!sub)
        return;
    //dg_scene_add_ent(scene, ent_music("./sound/click.ogg"));
    if (!(sub->data)) {
        sub_button = ent_button((sfVector2f){200, 200}, 100, "lol", NULL);
        sub->data = sub_button;
        dg_arr_add_end(entities, sub_button);
    }
}

sfVector2f *get_path(void)
{
    sfVector2f *path = malloc(sizeof(sfVector2f) * 5);

    path[0] = (sfVector2f) {500, 500};
    path[1] = (sfVector2f) {1000, 500};
    path[2] = (sfVector2f) {1200, 300};
    path[3] = (sfVector2f) {2000, 2000};
    path[4] = (sfVector2f) {-1, -1};
    return path;
}

dg_scene_t *scene_game(void)
{
    dg_scene_t *scene = dg_scene_create("game");
    dg_scene_t *scene_escape = 0;
    float rad = 10;

    scene_escape = dg_scene_manager_get_scene("escape_menu");
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, ent_music("./sound/theme_game.ogg"));
    dg_scene_add_ent(scene, ent_slot((sfVector2f){0, 0},
        (sfVector2f){0.5, 0.5}, &change_stat));
    dg_scene_add_ent(scene, ent_tower
        ((sfVector2f) {500, 500}, 0, &rad, 10));
    dg_scene_add_ent(scene, ent_map(2, 1, 0, 0));
    dg_scene_add_ent(scene, ent_monster((sfVector2f) {100, 100}, 0, 100));
    dg_scene_add_ent(scene, ent_path(get_path()));
    dg_scene_add_sys(scene, dg_system_create(&sys_tower_attack, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_camera, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_slot, 0));
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_escape, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_follow_path, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    return scene;
}