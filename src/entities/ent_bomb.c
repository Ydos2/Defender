/*
** EPITECH PROJECT, 2020
** ent_bomb
** File description:
** ent_bomb
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "enemy_data.h"

dg_entity_t *ent_bomb(enemy_data_t *m)
{
    dg_entity_t *entity = dg_entity_create("bomb");
    void *idata[1] = {0};

    dg_entity_add_component(entity, dg_cpt_pos(m->pos->x, m->pos->y));
    dg_entity_add_component(entity, cpt_scale(0.2, 0.2));
    dg_entity_add_component(entity, cpt_spritesheet(28));
    dg_entity_add_component(entity, cpt_script(&scp_boum_init,
        &scp_boum_loop, &scp_boum_end, idata));
    return entity;
}