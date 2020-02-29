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

static int go_to(sfVector2f *pos, sfVector2f target, float speed)
{
    if (target.x == -1 && target.y == -1)
    return 0;
    pos->x -= (pos->x > target.x) ? speed : 0;
    pos->x += (pos->x < target.x) ? speed : 0;
    pos->y -= (pos->y > target.y) ? speed : 0;
    pos->y += (pos->y < target.y) ? speed : 0;
    if (pos->y == target.y && pos->x == target.x)
        return 1;
    return 0;
}

void sys_follow_path(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *ent_path = dg_get_entity(*entities, "path");
    sfVector2f *path = (sfVector2f *)dg_entity_get_component(ent_path, "path");
    int *path_id = (int *)(dg_entity_get_component(entity, "path_follower"));
    sfVector2f *pos = (sfVector2f *)dg_entity_get_component(entity, "pos");

    if (!path || !path_id || !pos)
        return;
    *path_id += go_to(pos, path[*path_id], 0.5);
}