/*
** EPITECH PROJECT, 2020
** background_menu
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_entity_t *ent_sprite(int id)
{
    dg_entity_t *background_menu = dg_entity_create("sprite");

    dg_entity_add_component(background_menu, dg_cpt_pos(0, 0));
    dg_entity_add_component(background_menu, cpt_spritesheet(id));
    return background_menu;
}
