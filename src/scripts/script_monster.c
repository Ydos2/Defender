/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script_monster
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "tower_data.h"
#include "enemy_data.h"
#include "script.h"

const void (*monsterCreation[1])(dg_entity_t *) = {&monster_basic};

void *scp_monster_init(void *init_data)
{
    void **idata = (void **) init_data;
    enemy_data_t *data = malloc(sizeof(enemy_data_t));
    int id = 0;
    dg_component_t *position = 0;

    data->id = (int *)idata[0];
    id = *data->id;
    data->pos = (sfVector2f *)idata[1];
    data->entity = (dg_entity_t *)idata[2];
    data->health = (float *)idata[3];
    position = dg_cpt_pos(data->pos->x, data->pos->y);
    dg_entity_add_component(data->entity, position);
    data->pos = (sfVector2f *)position->data;
    dg_entity_add_component(data->entity, cpt_path_follower());
    monsterCreation[id](data->entity);
    return data;
}

void scp_monster_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    enemy_data_t *d = ((enemy_data_t *)data);

    if (*(d->health) <= 0)
        entity->destroy = 1;
}

void scp_monster_end(void *data)
{
    enemy_data_t *d = (enemy_data_t *)data;

    free(d);
}