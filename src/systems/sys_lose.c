/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sys_lose
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"
#include "ecs.h"

void sys_lose(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *ent_gd = dg_get_entity(*entities, "game_data");
    game_data_t *gd = dg_entity_get_component(ent_gd, "game_data");
    dg_scene_t *new_scene = 0;

    if (!gd)
        return;
    if (gd->health <= 0) {
        dg_scene_manager_add_scene(scene_lose());
        new_scene = dg_scene_manager_get_scene("scoreboard");
        new_scene->run = 1;
        new_scene->display = 1;
        dg_scene_manager_remove("game");
        dg_scene_manager_remove("escape_menu");
        gd->health = 3;
    }
}