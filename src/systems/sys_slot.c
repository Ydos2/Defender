/*
** EPITECH PROJECT, 2020
** sys_slot
** File description:
** sys_slot
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void sys_slot(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    dg_sysf_t action = (dg_sysf_t)(dg_entity_get_component(entity,
        "action_slot"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfIntRect *rect = (sfIntRect *)
        (dg_entity_get_component(entity, "box_collider"));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);

    if (!dg_system_require(entity, 3, "box_collider", "pos", "action_slot")
        || !camera)
        return;
    rect->left = pos->x;
    rect->top = pos->y;
    if (sfIntRect_contains(rect, mouse.x, mouse.y)
        && w->events.mouse_pressed_left)
        action(entity, w, entities, dt);
}