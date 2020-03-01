/*
** EPITECH PROJECT, 2020
** ent_slot
** File description:
** ent_slot
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_slot(sfVector2f pos, int id
    , void (*action)(int))
{
    dg_entity_t *slot = dg_entity_create("slot");

    dg_entity_add_component(slot, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(slot, cpt_scale(0.2, 0.2));
    dg_entity_add_component(slot, cpt_box_collider(0, 0, 60, 225));
    dg_entity_add_component(slot, cpt_action_slot(action));
    dg_entity_add_component(slot, cpt_spritesheet(4));
    return slot;
}