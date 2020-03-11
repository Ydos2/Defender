/*
** EPITECH PROJECT, 2020
** script_attack_tower
** File description:
** script_attack_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "tower_data.h"
#include "enemy_data.h"
#include "script.h"

typedef struct data {
    float *radius;
    sfVector2f *pos;
    dg_entity_t *entity;
    sfCircleShape *circle;
} data_t;

sfCircleShape *create_circle(float *rad, sfVector2f *pos)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f *pos_i;

    if (!circle)
        return NULL;
    pos_i->x = pos->x - *rad * 1.075;
    pos_i->y = pos->y - *rad * 1.075;
    sfCircleShape_setPosition(circle, *pos_i);
    sfCircleShape_setFillColor(circle, (sfColor){119, 239, 247, 25});
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1.5);
    sfCircleShape_setRadius(circle, *rad);
    pos->x -= *rad * 0.225;
    pos->y -= *rad * 0.225;
    return circle;
}

void *scp_tower_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));

    data->radius = (float *)idata[0];
    data->entity = (dg_entity_t *)idata[2];
    data->pos = (sfVector2f *)idata[1];
    data->circle = create_circle(data->radius, data->pos);
    dg_entity_add_component(data->entity,
        dg_cpt_pos(data->pos->x, data->pos->y));
    dg_entity_add_component(data->entity, cpt_spritesheet(7));
    return data;
}

void scp_tower_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);

    sfRenderWindow_drawCircleShape(w->window, d->circle, NULL);
}

void scp_tower_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}