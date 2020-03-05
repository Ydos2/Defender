/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sys_tower_spawn_range
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"
#include "general_data.h"
#include "ecs.h"

static const int distance = 200;

void sys_tower_spawn_range(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f *pos = dg_entity_get_component(entity, "pos");
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(w->window);
    dg_entity_t *game_data = dg_get_entity(*entities, "game_data");
    game_data_t *gd = (game_data_t *)(dg_entity_get_component
        (game_data, "game_data"));

    if (dg_strcmp("tower", entity->name))
        return;
    if (dg_square(pos->x - m_pos.x) + dg_square(pos->y - m_pos.y) <
        dg_square(distance))
        gd->can_spawn_tower = 0;
}