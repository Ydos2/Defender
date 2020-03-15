/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sys_follow_path
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"
#include "ecs.h"
#include "script.h"

static int go_to(sfVector2f *pos, sfVector2f target, float speed, int dt)
{
    float new_speed = speed * dt / 2000;

    if (target.x == -1 && target.y == -1)
        return 0;
    pos->x -= (pos->x > target.x) ? (int)(new_speed) : 0;
    pos->x += (pos->x < target.x) ? (int)(new_speed) : 0;
    pos->y -= (pos->y > target.y) ? (int)(new_speed) : 0;
    pos->y += (pos->y < target.y) ? (int)(new_speed) : 0;
    if (pos->y + 30 > target.y  && pos->y - 30 < target.y
        && pos->x + 30 > target.x && pos->x - 30 < target.x)
        return 1;
    return 0;
}

int is_slow(dg_entity_t *entity)
{
    void *data = 0;
    enemy_data_t *d = 0;

    if (!dg_strcmp(entity->name, "monster")) {
        data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
        d = ((enemy_data_t *)data);
        if (d->slow)
        return 1;
    }
    return 0;
}

void sys_follow_path(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *ent_path = dg_get_entity(*entities, "path");
    sfVector2f *path = (sfVector2f *)dg_entity_get_component(ent_path, "path");
    int *path_id = (int *)(dg_entity_get_component(entity, "path_follower"));
    sfVector2f *pos = (sfVector2f *)dg_entity_get_component(entity, "pos");
    dg_entity_t *ent_gd = dg_get_entity(*entities, "game_data");
    game_data_t *gd = dg_entity_get_component(ent_gd, "game_data");
    int speed = 0.5;

    if (!path || !path_id || !pos)
        return;
    if (is_slow(entity))
        speed /= 2;
    *path_id += go_to(pos, path[*path_id], 0.5, dt.microseconds);
    if (path[*path_id].x == -1 && path[*path_id].y == -1) {
        if (!dg_strcmp(entity->name, "monster"))
            gd->health--;
        entity->destroy = 1;
    }
}