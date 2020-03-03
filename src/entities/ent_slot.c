/*
** EPITECH PROJECT, 2020
** ent_slot
** File description:
** ent_slot
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_slot(sfVector2f pos, sfVector2f size
    , void (*action)(dg_entity_t *, dg_window_t *,
    dg_array_t **, sfTime))
{
    dg_entity_t *slot = dg_entity_create("slot");

    dg_entity_add_component(slot, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(slot, cpt_scale(size.x, size.y));
    dg_entity_add_component(slot, cpt_box_collider
        (0, 0, 220 * size.x, 220 * size.y));
    dg_entity_add_component(slot, cpt_action_slot(action));
    dg_entity_add_component(slot, cpt_spritesheet(5));
    dg_entity_add_component(slot, cpt_subentity(NULL));
    return slot;
}