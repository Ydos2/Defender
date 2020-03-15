/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tower menu script
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "tower_data.h"
#include "enemy_data.h"
#include "script.h"
#include "epitech_tools.h"

void init_tower_menu(tower_data_t *d, dg_array_t **entities)
{
    dg_entity_t *delete = ent_slot_delete(entities , *(d->pos),
        d->entity, COST[d->id] / 2);
    dg_entity_t *upgrade = ent_slot_upgrade(entities, *(d->pos),
        d->entity, d);

    d->buttons[0] = delete;
    d->buttons[1] = upgrade;
    dg_arr_add_end(entities, delete);
    dg_arr_add_end(entities, upgrade);
}

void launch_tower_menu(tower_data_t *d)
{
    if (d->stat) {
        d->buttons[0]->activated = 1;
        if (d->buttons[1])
            d->buttons[1]->activated = 1;
    } else {
        d->buttons[0]->activated = 0;
        if (d->buttons[1])
            d->buttons[1]->activated = 0;
    }
}