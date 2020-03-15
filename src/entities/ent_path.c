/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** ent_path
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_path(sfVector2f *vs)
{
    dg_entity_t *entity = dg_entity_create("path");

    dg_entity_add_component(entity, cpt_path(vs));
    return entity;
}

dg_entity_t *ent_path_bullet(sfVector2f *vs)
{
    dg_entity_t *entity = dg_entity_create("path_bullet");

    dg_entity_add_component(entity, cpt_path_bullet(vs));
    return entity;
}