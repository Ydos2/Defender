/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tag component
*/

#include <stdlib.h>
#include <stdarg.h>
#include "libdragon.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    sfVector2f *path = (sfVector2f *)data;

    free(path);
}

dg_component_t *cpt_path(sfVector2f *vs)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfVector2f *path = vs;
    dg_component_t *component = dg_component_create("path", path, destroy);

    return component;
}

dg_component_t *cpt_path_bullet(sfVector2f *vs)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    sfVector2f *path = vs;
    dg_component_t *component = dg_component_create
        ("path_bullet", path, destroy);

    return component;
}