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

typedef struct buttons {
    dg_entity_t **buttons;
    sfVector2f *pos;
} buttons_t;

typedef struct data {
    dg_entity_t *camera;
    sfVector2f *pos;
    sfIntRect *collider;
    buttons_t buttons;
} data_t;

void init_build_buttons(data_t *data, dg_entity_t *entity, dg_scene_t *scene)
{
    data->buttons.buttons = malloc(sizeof(dg_entity_t *) * 5);
    data->buttons.pos = malloc(sizeof(sfVector2f) * 4);

    data->buttons.buttons[0] = ent_slot(scene, (sfVector2f){0, 0}, 0, 5);
    data->buttons.buttons[1] = ent_slot(scene, (sfVector2f){0, 0}, 1, 10);
    data->buttons.buttons[2] = ent_slot(scene, (sfVector2f){0, 0}, 2, 20);
    data->buttons.buttons[3] = ent_slot(scene, (sfVector2f){0, 0}, 3, 30);
    data->buttons.buttons[4] = NULL;
    data->buttons.pos[0] = (sfVector2f){400, 0};
    data->buttons.pos[1] = (sfVector2f){700, 0};
    data->buttons.pos[2] = (sfVector2f){1000, 0};
    data->buttons.pos[3] = (sfVector2f){1300, 0};
    for (int i = 0; data->buttons.buttons[i]; i++) {
        dg_scene_add_ent(scene, data->buttons.buttons[i]);
    }
}

void build_buttons_update_pos(data_t *data)
{
    sfVector2f *pos = 0;

    for (int i = 0; data->buttons.buttons[i]; i++) {
        pos = dg_entity_get_component(data->buttons.buttons[i], "pos");
        pos->x = data->pos->x + data->buttons.pos[i].x;
    }
}

void *scp_build_menu_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[0];
    dg_scene_t *scene = idata[2];
    dg_component_t *pos = dg_cpt_pos(-2450, 0);
    dg_component_t *collider = cpt_box_collider(-1900, -10, 100, 2000);

    data->collider = collider->data;
    data->pos = pos->data;
    data->camera = idata[1];
    init_build_buttons(data, entity, scene);
    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, collider);
    return data;
}

void scp_build_menu_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);
    sfVector2f *camera = dg_entity_get_component(data->camera, "pos");

    data->collider->left = data->pos->x;
    data->collider->top = data->pos->y;
    build_buttons_update_pos(data);
    if (sfIntRect_contains(data->collider, mouse.x, mouse.y)) {
        data->pos->x = 0;
    } else {
        data->pos->x = -1900;
    }
    
}

void scp_build_menu_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}