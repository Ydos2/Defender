/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script upgrade buttons
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "script.h"

typedef struct data {
    game_data_t *game_data;
    sfVector2f *pos;
    sfIntRect *collider;
    sfColor *color;
    dg_entity_t *tower;
    tower_data_t *td;
} data_t;

static void set_button_color(data_t *d, sfVector2i mouse, int cost)
{
    *(d->color) = (sfColor){255, 255, 255, 255};
    *(d->color) = (cost <= d->game_data->money
        && sfIntRect_contains(d->collider, mouse.x, mouse.y)) ?
        (sfColor){200, 200, 200, 255} : *(d->color);
    *(d->color) = (d->game_data->money < cost) ?
        (sfColor){255, 100, 100, 255} : *(d->color);
}

void *scp_upgrade_buttons_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_array_t **entities = (dg_array_t **)idata[0];
    dg_entity_t *ent_gd = dg_get_entity(*entities, "game_data");
    dg_entity_t *entity = (dg_entity_t *)idata[1];
    sfVector2f pos = *((sfVector2f *)idata[2]);
    dg_component_t *collider = cpt_box_collider(0, 0, 220 * 0.3, 220 * 0.3);
    dg_component_t *cpos = dg_cpt_pos(pos.x + 130, pos.y - 15);
    dg_component_t *ccolor = cpt_color((sfColor){255, 255, 255, 255});

    data->pos = (sfVector2f *)cpos->data;
    data->game_data = dg_entity_get_component(ent_gd, "game_data");
    data->collider = collider->data;
    data->color = (sfColor *)ccolor->data;
    data->tower = (dg_entity_t *)idata[3];
    data->td = (tower_data_t *)idata[4];
    dg_entity_add_component(entity, collider);
    dg_entity_add_component(entity, cpos);
    dg_entity_add_component(entity, ccolor);
    return data;
}

void scp_upgrade_buttons_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);
    int cost = COST[d->td->id] * 2;

    d->collider->left = d->pos->x;
    d->collider->top = d->pos->y;
    if (cost <= d->game_data->money && w->events.mouse_pressed_left
        && sfIntRect_contains(d->collider, mouse.x, mouse.y)) {
        d->game_data->money -= cost;
        d->td->id += 4;
        d->td->radius *= 1.5;
        d->td->sheet->data = dg_ressources_get_spritesheet(11 + d->td->id);
        entity->destroy = 1;
        d->td->buttons[1] = 0;
    }
    set_button_color(d, mouse, cost);
}

void scp_upgrade_buttons_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}