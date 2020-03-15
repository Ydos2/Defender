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

dg_entity_t *ent_slot_upgrade(dg_array_t **entities,
    sfVector2f pos, dg_entity_t *tower, tower_data_t *td)
{
    dg_entity_t *slot = dg_entity_create("delete_button");
    void *idata[5] = {entities, slot, &pos, tower, td};

    dg_entity_add_component(slot, cpt_scale(0.3, 0.3));
    dg_entity_add_component(slot, cpt_script(&scp_upgrade_buttons_init,
        &scp_upgrade_buttons_loop, &scp_upgrade_buttons_end, idata));
    dg_entity_add_component(slot, cpt_spritesheet(td->id + 23));
    slot->activated = 0;
    return slot;
}