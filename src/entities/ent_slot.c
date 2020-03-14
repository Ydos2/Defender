/*
** EPITECH PROJECT, 2020
** ent_slot
** File description:
** ent_slot
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_entity_t *ent_slot(dg_scene_t *scene, sfVector2f pos, int id, int price)
{
    dg_entity_t *slot = dg_entity_create("build_button");
    void *idata[5] = {scene, slot, &id, &price, &pos};

    dg_entity_add_component(slot, cpt_scale(0.4, 0.4));
    dg_entity_add_component(slot, cpt_script(&scp_build_buttons_init,
        scp_build_buttons_loop, scp_build_buttons_end, idata));
    dg_entity_add_component(slot, cpt_spritesheet(id + 5));
    return slot;
}