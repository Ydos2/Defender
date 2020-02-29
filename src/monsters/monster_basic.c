/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** monster basic
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static dg_animator_t *set_player_animator(void)
{
    dg_animator_t *animator = dg_animator_create();
    dg_spritesheet_t *ss = dg_ressources_get_spritesheet(4);
    dg_animation_t *up = dg_animation_create(ss, 8);

    dg_animation_add(up, 0);
    dg_animation_add(up, 1);
    dg_animation_add(up, 2);
    dg_animation_add(up, 1);
    dg_animator_add(animator, "up", up);
    return animator;
}

void monster_basic(dg_entity_t *entity)
{
    dg_entity_add_component(entity, dg_cpt_animator(&set_player_animator));
}