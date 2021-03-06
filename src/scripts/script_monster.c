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

void scp_monster_init_next(enemy_data_t *data)
{
    data->health = 100;
    data->poison = 0;
    data->slow = 0;
    data->poison_delay = 0;
    data->slow_delay = 0;
}

void *scp_monster_init(void *init_data)
{
    void **idata = (void **) init_data;
    enemy_data_t *data = malloc(sizeof(enemy_data_t));
    int id = 0;
    dg_component_t *position = 0;
    dg_component_t *color = cpt_color((sfColor){255, 255, 255, 255});

    data->id = (int *)idata[0];
    id = *data->id;
    data->pos = (sfVector2f *)idata[1];
    data->entity = (dg_entity_t *)idata[2];
    data->color = (sfColor *)color->data;
    scp_monster_init_next(data);
    position = dg_cpt_pos(data->pos->x, data->pos->y);
    dg_entity_add_component(data->entity, position);
    data->pos = (sfVector2f *)position->data;
    dg_entity_add_component(data->entity, cpt_path_follower());
    dg_entity_add_component(data->entity, color);
    monsterCreation[id](data->entity);
    return data;
}

static void change_color(enemy_data_t *d)
{
    *(d->color) = (sfColor){255, 255, 255, 255};
    *(d->color) = (d->slow) ?
        (sfColor){200, 200, 255, 255} : *(d->color);
    *(d->color) = (d->poison) ?
        (sfColor){255, 100, 255, 255} : *(d->color);
}

void scp_monster_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    enemy_data_t *d = ((enemy_data_t *)data);
    dg_entity_t *ent_gd = dg_get_entity(*entities, "game_data");
    game_data_t *gd = (game_data_t *)dg_entity_get_component
        (ent_gd, "game_data");

    if (d->poison)
        d->health -= 1 * dt.microseconds / 300000.0;
    if (d->health <= 0) {
        entity->destroy = 1;
        gd->money++;
    }
    d->poison_delay += dt.microseconds / 2000.0;
    d->slow_delay += dt.microseconds / 2000.0;
    d->poison = (d->poison_delay > 2000.0) ? 0 : d->poison;
    d->slow = (d->slow_delay > 2000.0) ? 0 : d->slow;
    change_color(d);
}

void scp_monster_end(void *data)
{
    enemy_data_t *d = (enemy_data_t *)data;

    free(d);
}