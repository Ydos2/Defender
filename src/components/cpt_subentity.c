/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** cpt_subentity
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    (void)data;
}

dg_component_t *cpt_subentity(dg_entity_t **entity)
{
    void (*destroy)(void *) = &component_destroy;
    dg_component_t *component = dg_component_create
        ("subentity", entity, destroy);

    return component;
}