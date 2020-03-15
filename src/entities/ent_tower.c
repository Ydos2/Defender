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

const void (*towerCreation[4])(dg_entity_t *) = {&tower_basic, &tower_basic,
    &tower_basic, &tower_basic};

dg_entity_t *ent_tower(dg_array_t **entities, sfVector2f pos, int id, int delay)
{
    dg_entity_t *entity = dg_entity_create("tower");
    int delay_max = 20;
    void *idata[6] = {entities, &pos, entity, &delay, &delay_max, &id};

    dg_entity_add_component(entity, cpt_script(&scp_tower_init, scp_tower_loop,
        scp_tower_end, idata));
    towerCreation[id](entity);
    return entity;
}