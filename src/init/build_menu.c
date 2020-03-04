/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** build_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

void id(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *ent_gd = dg_get_entity(*entities, "game_data");
    game_data_t *gd = dg_entity_get_component(ent_gd, "game_data");

    if (!gd)
        return;
    gd->build_id = 0;
}

void build_menu(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("game");
    dg_component_t *sub = (dg_component_t *)
        dg_entity_get_full_component(entity, "subentity");
    dg_entity_t *sub_ent = 0;

    if (!sub)
        return;
    if (!(sub->data)) {
        sub_ent = ent_slot((sfVector2f){200, 200}, (sfVector2f){1, 1}, &id);
        dg_arr_add_end((dg_array_t **)(&(sub->data)), sub_ent);
        dg_arr_add_end(entities, sub_ent);
        printf("slot created\n");
    } else {
        dg_arr_free_all(&(sub->data));
        sub->data = NULL;
    }
}