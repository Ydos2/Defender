/*
** EPITECH PROJECT, 2020
** script_attack_tower
** File description:
** script_attack_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "tower_data.h"
#include "enemy_data.h"
#include "script.h"
#include "epitech_tools.h"

sfCircleShape *create_circle(float rad, sfVector2f *pos)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos_i;

    if (!circle)
        return NULL;
    pos_i.x = pos->x - rad * 1.075;
    pos_i.y = pos->y - rad * 1.075;
    sfCircleShape_setPosition(circle, pos_i);
    sfCircleShape_setFillColor(circle, (sfColor){119, 239, 247, 25});
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1.5);
    sfCircleShape_setRadius(circle, rad);
    pos->x -= rad * 0.225;
    pos->y -= rad * 0.225;
    return circle;
}

void *scp_tower_init(void *init_data)
{
    void **idata = (void **) init_data;
    tower_data_t *data = malloc(sizeof(tower_data_t));
    dg_component_t *position = 0;

    data->radius = 200;
    data->entity = (dg_entity_t *)idata[2];
    data->pos = (sfVector2f *)idata[1];
    data->delay_max = (float)(*((int *)idata[3]));
    data->delay = (float)(*((int *)idata[4]));
    data->id = *((int *)idata[5]);
    data->circle = create_circle(data->radius, data->pos);
    data->sheet = cpt_spritesheet(11 + data->id);
    position = dg_cpt_pos(data->pos->x, data->pos->y);
    dg_entity_add_component(data->entity, position);
    data->pos = (sfVector2f *)position->data;
    dg_entity_add_component(data->entity, data->sheet);
    data->stat = 0;
    init_tower_menu(data, (dg_array_t **)(idata[0]));
    return data;
}

void draw_circle_shape(dg_window_t *w, tower_data_t *d, sfVector2i mouse_pos)
{
    if ((mouse_pos.x <= (d->pos->x + 75) && mouse_pos.x >= (d->pos->x)
        && mouse_pos.y <= (d->pos->y + 75) && mouse_pos.y >= (d->pos->y))
        || d->stat) {
        sfRenderWindow_drawCircleShape(w->window, d->circle, NULL);
        if (w->events.mouse_pressed_left)
            d->stat = (d->stat) ? 0 : 1;
    }
}

void scp_tower_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    tower_data_t *d = ((tower_data_t *)data);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(w->window);
    dg_array_t *ent_list = *entities;
    dg_entity_t *ent = 0;
    sfVector2f pos = {d->pos->x + d->radius * 0.225,
        d->pos->y + d->radius * 0.225};

    d->delay += dt.microseconds / 4000;
    for (; ent_list; ent_list = ent_list->next) {
        ent = ent_list->data;
        attack_tower(ent, data, d, entities);
    }
    if (d->id != 0 && d->id != 4 && d->delay > d->delay_max)
        d->delay = 0;
    draw_circle_shape(w, d, mouse_pos);
    launch_tower_menu(d);
    sfCircleShape_destroy(d->circle);
    create_circle(d->radius, &pos);
}

void scp_tower_end(void *data)
{
    tower_data_t *d = (tower_data_t *)data;

    free(d);
}