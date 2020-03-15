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

dg_entity_t *ent_castle(void)
{
    dg_entity_t *slot = dg_entity_create("castle");
    void *idata[5] = {slot};

    dg_entity_add_component(slot, cpt_scale(0.4, 0.4));
    dg_entity_add_component(slot, cpt_script(&scp_build_buttons_init,
        scp_build_buttons_loop, scp_build_buttons_end, idata));
    return slot;
}