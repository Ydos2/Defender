/*
** EPITECH PROJECT, 2020
** cpt_text
** File description:
** cpt_text
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"

static void component_text_destroy(void *data)
{
    sfText *text = (sfText *)(data);

    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

dg_component_t *component_text_create(int scale,
    char *content)
{
    void (*destroy)(void *) = &component_text_destroy;
    sfText *text = sfText_create();
    dg_component_t *component = dg_component_create("text", text, destroy);

    sfText_setFont (text, sfFont_createFromFile("./font/Krisha-Regular.otf"));
    sfText_setCharacterSize(text, scale);
    sfText_setString(text, content);
    return component;
}

void system_display_text(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfText *text = (sfText *)(dg_entity_get_component(entity, "text"));
    sfVector2f *scale = (sfVector2f *)
        (dg_entity_get_component(entity, "scale"));

    if (!dg_system_require(entity, 2, "text", "pos"))
        return;
    sfText_setPosition(text, *pos);
    if (scale)
        sfText_setCharacterSize(text, scale->x * 275);
    sfRenderWindow_drawText(w->window, text, 0);
}