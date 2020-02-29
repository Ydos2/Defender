/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** ent_monster
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

const void (*monsterCreation[1])(dg_entity_t *) = {&monster_basic};

dg_entity_t *ent_monster(sfVector2f pos, int id)
{
    dg_entity_t *entity = dg_entity_create("monster");

    dg_entity_add_component(entity, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(entity, cpt_path_follower());
    monsterCreation[id](entity);
    return entity;
}