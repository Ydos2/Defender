/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** castle entity
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "general_data.h"

dg_entity_t *ent_castle(sfVector2f pos, game_data_t *gd)
{
    dg_entity_t *slot = dg_entity_create("castle");
    void *idata[2] = {slot, gd};

    dg_entity_add_component(slot, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(slot, cpt_scale(1, 1));
    dg_entity_add_component(slot, cpt_spritesheet(10));
    dg_entity_add_component(slot, cpt_box_collider(0, 0, 700, 700));
    dg_entity_add_component(slot, cpt_script(&scp_castle_init,
        &scp_castle_loop, &scp_castle_end, idata));
    return slot;
}