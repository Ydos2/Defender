/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script build buttons
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "script.h"

typedef struct data {
    game_data_t *game_data;
    int build_id;
    int cost;
    sfVector2f *pos;
    sfIntRect *collider;
    sfColor *color;
} data_t;

void *scp_build_buttons_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = (dg_scene_t *)idata[0];
    dg_entity_t *ent_gd = dg_get_entity(scene->entities, "game_data");
    dg_entity_t *entity = (dg_entity_t *)idata[1];
    sfVector2f pos = *((sfVector2f *)idata[4]);
    dg_component_t *collider = cpt_box_collider(0, 0, 220 * 0.5, 220 * 0.5);
    dg_component_t *cpos = dg_cpt_pos(pos.x, pos.y);
    dg_component_t *ccolor = cpt_color((sfColor){255, 255, 255, 255});

    data->pos = (sfVector2f *)cpos->data;
    data->game_data = dg_entity_get_component(ent_gd, "game_data");
    data->collider = collider->data;
    data->color = (sfColor *)ccolor->data;
    dg_entity_add_component(entity, collider);
    dg_entity_add_component(entity, cpos);
    dg_entity_add_component(entity, ccolor);
    data->build_id = *((int *)idata[2]);
    data->cost = *((int *)idata[3]);
    return data;
}

static void set_button_color(data_t *d, sfVector2i mouse)
{
    *(d->color) = (sfColor){255, 255, 255, 255};
    *(d->color) = (d->cost <= d->game_data->money
        && sfIntRect_contains(d->collider, mouse.x, mouse.y)) ?
        (sfColor){200, 200, 200, 255} : *(d->color);
    *(d->color) = (d->game_data->money < d->cost) ?
        (sfColor){255, 100, 100, 255} : *(d->color);
    *(d->color) = (d->game_data->build_id == d->build_id) ?
        (sfColor){230, 255, 100, 255} : *(d->color);
    *(d->color) = (d->game_data->money < d->cost) ?
        (sfColor){255, 100, 100, 255} : *(d->color);
}

void scp_build_buttons_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);

    d->collider->left = d->pos->x;
    d->collider->top = d->pos->y;
    if (d->cost <= d->game_data->money &&  w->events.mouse_pressed_left
        && sfIntRect_contains(d->collider, mouse.x, mouse.y)) {
        if (d->game_data->build_id != d->build_id)
            d->game_data->build_id = d->build_id;
        else
            d->game_data->build_id = -1;
        w->events.mouse_pressed_left = 0;
    }
    set_button_color(d, mouse);
}

void scp_build_buttons_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}