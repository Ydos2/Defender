/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** build id component
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    int *id = (int *) data;

    free(id);
}

dg_component_t *cpt_build_id(int id)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    int *cid = malloc(sizeof(int));
    dg_component_t *component = dg_component_create("build_id",
        cid, destroy);

    *cid = id;
    return component;
}
