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
    enemy_data_t *m;
    sfVector2f pos_m_max;
} data_t;

static sfVector2f *game_path(sfVector2f *pos)
{
    sfVector2f *path = malloc(sizeof(sfVector2f) * 1);

    path[0] = (sfVector2f) {pos->x, pos->y};
    return path;
}

void *scp_bullet_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_component_t *position = 0;
    dg_scene_t *scene = dg_scene_manager_get_scene("game");

    data->pos = (sfVector2f *)idata[0];
    data->entity = (dg_entity_t *)idata[1];
    data->m = (enemy_data_t *)idata[2];
    position = dg_cpt_pos(data->pos->x, data->pos->y);
    dg_entity_add_component(data->entity, position);
    data->pos = (sfVector2f *)position->data;
    dg_scene_add_ent(scene, ent_path_bullet(game_path(data->m->pos)));
    dg_entity_add_component(data->entity, cpt_spritesheet(9));
    dg_entity_add_component(data->entity, cpt_path_bullet_follow());
    data->pos_m_max.x = data->pos->x;
    data->pos_m_max.y = data->pos->y;
    return data;
}

void scp_bullet_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);

    if (d->pos->x >= d->pos_m_max.x - 25 &&
        d->pos->x <= d->pos_m_max.x + 25 &&
        d->pos->x >= d->pos_m_max.x - 25 &&
        d->pos->y <= d->pos_m_max.x + 25)
        entity->destroy = 1;
}

void scp_bullet_end(void *data)
{
    enemy_data_t *d = (enemy_data_t *)data;

    free(d);
}