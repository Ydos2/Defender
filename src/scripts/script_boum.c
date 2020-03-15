/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script boum
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "script.h"

typedef struct data {
    int delay;
} data_t;

void *scp_boum_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));

    return data;
}

void scp_boum_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);

    d->delay += dt.microseconds;
    if (d->delay >= 100000)
        entity->destroy = 1;
}

void scp_boum_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}