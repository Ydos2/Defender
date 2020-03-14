/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** build id
*/

#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

void set_build_id(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *ent_gd = dg_get_entity(*entities, "game_data");
    game_data_t *gd = dg_entity_get_component(ent_gd, "game_data");
    int *build_id = dg_entity_get_component(entity, "build_id");

    if (!gd)
        return;
    gd->build_id = *build_id;
}