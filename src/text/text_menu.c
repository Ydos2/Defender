/*
** EPITECH PROJECT, 2020
** text_menu
** File description:
** text_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *entity_text_create(void)
{
    dg_entity_t *text_menu = dg_entity_create("text_menu");

    dg_entity_add_component(text_menu, dg_cpt_pos(800, 200));
    dg_entity_add_component(text_menu
        , component_text_create(200, "Menu"));
    return text_menu;
}