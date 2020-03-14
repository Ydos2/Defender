/*
** EPITECH PROJECT, 2020
** script_bullet
** File description:
** script_bullet
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "tower_data.h"
#include "enemy_data.h"
#include "script.h"

typedef struct data {
    sfVector2f *pos;
    dg_entity_t *entity;
} data_t;

void *scp_bullet_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_component_t *position = 0;

    data->pos = (sfVector2f *)idata[0];
    data->entity = (dg_entity_t *)idata[1];
    position = dg_cpt_pos(data->pos->x, data->pos->y);
    dg_entity_add_component(data->entity, position);
    data->pos = (sfVector2f *)position->data;
    dg_entity_add_component(data->entity, cpt_spritesheet(9));
    dg_entity_add_component(data->entity, cpt_path_follower());
    return data;
}

void scp_bullet_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *monster = ((script_t *)dg_entity_get_component
        (entity, "script"))->data;
    enemy_data_t *m = ((enemy_data_t *)monster);
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);

    if (d->pos->x == m->pos->x)
        entity->destroy = 1;
}

void scp_bullet_end(void *data)
{
    enemy_data_t *d = (enemy_data_t *)data;

    free(d);
}