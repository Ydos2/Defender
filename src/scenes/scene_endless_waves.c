/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** scene_endless_waves
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

static sfVector2f *game_path(void)
{
    sfVector2f *path = malloc(sizeof(sfVector2f) * 8);

    path[0] = (sfVector2f) {0, 200};
    path[1] = (sfVector2f) {730, 200};
    path[2] = (sfVector2f) {750, 500};
    path[3] = (sfVector2f) {290, 500};
    path[4] = (sfVector2f) {290, 800};
    path[5] = (sfVector2f) {1450, 800};
    path[6] = (sfVector2f) {1450, 500};
    path[7] = (sfVector2f) {-1, -1};
    return path;
}

static void scene_add_ent(dg_scene_t *scene)
{
    dg_entity_t *gd = ent_game_data();
    game_data_t *game_data = dg_entity_get_component(gd, "game_data");

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_ent(scene, ent_music("./sound/theme_game.ogg"));
    dg_scene_add_ent(scene, ent_slot((sfVector2f){0, 0},
        (sfVector2f){0.5, 0.5}, &build_menu));
    dg_scene_add_ent(scene, ent_map(6, 1, 0, 0));
    dg_scene_add_ent(scene, ent_monster((sfVector2f) {-10, 200}, 0));
    dg_scene_add_ent(scene, ent_path(game_path()));
    dg_scene_add_ent(scene, gd);
    dg_scene_add_ent(scene, ent_score((sfVector2f) {1630, 0}, 80,
        "money : ", &(game_data->money)));
}

static void scene_add_sys(dg_scene_t *scene)
{
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_tower_spawn_range, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_slot, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_escape, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_follow_path, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_create_tower, 0));
}

dg_scene_t *scene_endless_waves(void)
{
    dg_scene_t *scene = dg_scene_create("game");

    scene_add_ent(scene);
    scene_add_sys(scene);
    scene->display = 1;
    scene->run = 1;
    return scene;
}