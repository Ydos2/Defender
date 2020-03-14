/*
** EPITECH PROJECT, 2020
** ent_tower
** File description:
** ent_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

const void (*towerCreation[1])(dg_entity_t *) = {&tower_basic};

dg_entity_t *ent_tower(sfVector2f pos, int id, float *radius, int delay)
{
    dg_entity_t *entity = dg_entity_create("tower");
    int delay_max = 0;
    void *idata[5] = {radius, &pos, entity, &delay, &delay_max};

    dg_entity_add_component(entity, cpt_script(&scp_tower_init, scp_tower_loop,
        scp_tower_end, idata));
    towerCreation[id](entity);
    return entity;
}