/*
** EPITECH PROJECT, 2020
** sys_tower_attack
** File description:
** sys_tower_attack
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"
#include "general_data.h"
#include "ecs.h"

sfCircleShape *createCircle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    if (!circle)
        return NULL;
    sfCircleShape_setFillColor(circle, sfBlack);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 5.0f);
    return circle;
}

void sys_tower_attack(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfCircleShape *circle = NULL;

    circle = createCircle();
    sfRenderWindow_drawCircleShape(w->window, circle, NULL);
}