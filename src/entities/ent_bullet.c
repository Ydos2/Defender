/*
** EPITECH PROJECT, 2020
** ent_bullet
** File description:
** ent_bullet
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_entity_t *ent_bullet(sfVector2f *pos)
{
    dg_entity_t *entity = dg_entity_create("bullet");
    void *idata[4] = {pos, entity};

    dg_entity_add_component(entity, cpt_script(&scp_bullet_init,
        scp_bullet_loop, scp_bullet_end, idata));
    return entity;
}