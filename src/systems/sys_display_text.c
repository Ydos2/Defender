/*
** EPITECH PROJECT, 2020
** cpt_text
** File description:
** cpt_text
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void set_text_offset(dg_window_t *w, sfVector2f pos, sfText *text,
    sfVector2f *scale)
{
    sfVector2f text_pos = sfText_getPosition(text);
    int text_scale = sfText_getCharacterSize(text);
    sfVector2f new_pos = {pos.x + text_pos.x, pos.y + text_pos.y};
    int new_scale =  text_scale;

    new_scale *= (scale) ? scale->x : 1;
    sfText_setCharacterSize(text, new_scale);
    sfText_setPosition(text, new_pos);
    sfRenderWindow_drawText(w->window, text, 0);
    sfText_setPosition(text, text_pos);
    sfText_setCharacterSize(text, text_scale);
}

void sys_display_text(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfText *text = (sfText *)(dg_entity_get_component(entity, "text"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));

    if (!dg_system_require(entity, 2, "text", "pos"))
        return;
    set_text_offset(w, *pos, text, scale);
}
