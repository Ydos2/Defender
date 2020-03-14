/*
** EPITECH PROJECT, 2020
** cpt_path_bullet
** File description:
** cpt_path_bullet
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    int *id = (int *)data;

    free(id);
}

dg_component_t *cpt_path_bullet(void)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    int *id = malloc(sizeof(int));
    dg_component_t *component = dg_component_create(
        "path_follower", id, destroy);

    *id = 0;
    return component;
}
