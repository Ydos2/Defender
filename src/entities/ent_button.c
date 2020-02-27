/*
** EPITECH PROJECT, 2020
** cpt_button
** File description:
** cpt_button
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void set_button_scale(dg_entity_t *button, int size, char *text,
    dg_spritesheet_t *img)
{
    int tlen = 0;
    float img_relative_pixel = 1.0 / img->x;
    float img_y = 1.0 / img->y;
    float new_img_size = 0;
    int text_centered_pos = 0;

    for (tlen = 0; text && text[tlen] != '\n' && text[tlen] != '\0'; tlen++);
    new_img_size = (tlen + 2) * img_relative_pixel * size;
    text_centered_pos = ((new_img_size * img->x) / 2) - (size * 0.65 * (tlen / 2));
    dg_entity_add_component(button, cpt_scale(new_img_size, img_y * size * 3.3));
    dg_entity_add_component(button, cpt_text((sfVector2f){text_centered_pos, 0}, 470, text));
    dg_entity_add_component(button, cpt_box_collider(0, 0, size * 3.3, new_img_size * img->x));
}

dg_entity_t *ent_button(sfVector2f pos, int size, char *text
    , void (*action)(dg_window_t *))
{
    dg_entity_t *button = dg_entity_create("button");

    dg_entity_add_component(button, dg_cpt_pos(pos.x, pos.y));
    set_button_scale(button, size, text, dg_ressources_get_spritesheet(1));
    dg_entity_add_component(button, cpt_action(action));
    dg_entity_add_component(button, cpt_spritesheet(1));
    return button;
}
