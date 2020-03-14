/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** ent_monster
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_entity_t *ent_monster(sfVector2f pos, int id, float health)
{
    dg_entity_t *entity = dg_entity_create("monster");
    void *idata[4] = {&id, &pos, entity, &health};

    dg_entity_add_component(entity, cpt_script(&scp_monster_init,
        scp_monster_loop, scp_monster_end, idata));
    return entity;
}