/*
** EPITECH PROJECT, 2020
** ent_slot
** File description:
** ent_slot delete
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_entity_t *ent_slot_delete(dg_array_t **entities,
    sfVector2f pos, dg_entity_t *tower, int price)
{
    dg_entity_t *slot = dg_entity_create("delete_button");
    void *idata[5] = {entities, slot, &pos, tower, &price};

    dg_entity_add_component(slot, cpt_scale(0.4, 0.4));
    dg_entity_add_component(slot, cpt_script(&scp_delete_buttons_init,
        scp_delete_buttons_loop, scp_delete_buttons_end, idata));
    dg_entity_add_component(slot, cpt_spritesheet(27));
    slot->activated = 0;
    return slot;
}