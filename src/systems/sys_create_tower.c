/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sys_create_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

static void spawn_tower(game_data_t *gd,
    sfVector2i mouse, dg_array_t **entities)
{
    float rad = 200;

    (gd->build_id == 0) ? dg_arr_add_end(entities, ent_tower(
            (sfVector2f){mouse.x, mouse.y}, 0, &rad, 250)) : 0;
    (gd->build_id == 0) ? gd->money -= 5 : 0;
    (gd->build_id == 1) ? dg_arr_add_end(entities, ent_tower(
            (sfVector2f){mouse.x, mouse.y}, 1, &rad, 250)) : 0;
    (gd->build_id == 1) ? gd->money -= 10 : 0;
    (gd->build_id == 2) ? dg_arr_add_end(entities, ent_tower(
            (sfVector2f){mouse.x, mouse.y}, 2, &rad, 250)) : 0;
    (gd->build_id == 2) ? gd->money -= 20 : 0;
    (gd->build_id == 3) ? dg_arr_add_end(entities, ent_tower(
            (sfVector2f){mouse.x, mouse.y}, 3, &rad, 250)) : 0;
    (gd->build_id == 3) ? gd->money -= 30 : 0;
}

void sys_create_tower(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    game_data_t *gd = (game_data_t *)(dg_entity_get_component
        (entity, "game_data"));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);

    if (!gd)
        return;
    if (w->events.mouse_pressed_left) {
        if (gd->can_spawn_tower)
            spawn_tower(gd, mouse, entities);
        gd->build_id = -1;
    }
    gd->build_id = (w->events.mouse_pressed_right) ? -1 : gd->build_id;
    gd->can_spawn_tower = 1;
}