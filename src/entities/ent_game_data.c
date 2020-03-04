/*
** EPITECH PROJECT, 2020
** ent_map
** File description:
** ent_map
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_game_data(void)
{
    dg_entity_t *entity = dg_entity_create("game_data");

    dg_entity_add_component(entity, cpt_game_data());
    return entity;
}