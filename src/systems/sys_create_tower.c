/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sys_create_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

void sys_create_tower(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    game_data_t *gd = (game_data_t *)(dg_entity_get_component
        (entity, "game_data"));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w->window);

    if (!gd)
        return;
    if (gd->build_id == 0 && sfMouse_isButtonPressed(sfMouseLeft))
        dg_arr_add_end(entities, ent_monster(
            (sfVector2f){mouse.x, mouse.y}, 0));
}