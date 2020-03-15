/*
** EPITECH PROJECT, 2020
** script_attack_tower
** File description:
** script_attack_tower
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "tower_data.h"
#include "enemy_data.h"
#include "script.h"
#include "epitech_tools.h"

void arrow_attack(dg_entity_t *ent, void *data, tower_data_t *d,
    dg_array_t **entities)
{
    enemy_data_t *data_monster = NULL;
    tower_data_t *m = NULL;
    int monster_detection = 0;
    float distance = 0;

    if (!dg_strcmp(ent->name, "monster")) {
        data_monster = ((script_t *)dg_entity_get_component
            (ent, "script"))->data;
        m = ((tower_data_t *)data);
        distance = dg_square(d->pos->x - data_monster->pos->x)
            + dg_square(d->pos->y - data_monster->pos->y);
        monster_detection = (distance <= dg_square(d->radius)) ? 1 : 0;
        if (d->delay >= d->delay_max && monster_detection == 1) {
            data_monster->health -= 25;
            dg_arr_add_end(entities, ent_bullet(d->pos, data_monster));
            d->delay = 0;
        }
    }
}

void canon_attack(dg_entity_t *ent, void *data, tower_data_t *d,
    dg_array_t **entities)
{
    enemy_data_t *data_monster = NULL;
    tower_data_t *m = NULL;
    int monster_detection = 0;
    float distance = 0;

    if (!dg_strcmp(ent->name, "monster")) {
        data_monster = ((script_t *)dg_entity_get_component
            (ent, "script"))->data;
        m = ((tower_data_t *)data);
        distance = dg_square(d->pos->x - data_monster->pos->x)
            + dg_square(d->pos->y - data_monster->pos->y);
        monster_detection = (distance <= dg_square(d->radius)) ? 1 : 0;
        if (d->delay >= d->delay_max && monster_detection == 1)
            data_monster->health -= 5;
    }
}

void blue_attack(dg_entity_t *ent, void *data, tower_data_t *d,
    dg_array_t **entities)
{
        enemy_data_t *data_monster = NULL;
    tower_data_t *m = NULL;
    int monster_detection = 0;
    float distance = 0;

    if (!dg_strcmp(ent->name, "monster")) {
        data_monster = ((script_t *)dg_entity_get_component
            (ent, "script"))->data;
        m = ((tower_data_t *)data);
        distance = dg_square(d->pos->x - data_monster->pos->x)
            + dg_square(d->pos->y - data_monster->pos->y);
        monster_detection = (distance <= dg_square(d->radius)) ? 1 : 0;
        if (d->delay >= d->delay_max && monster_detection == 1)
            data_monster->health -= 1;
            data_monster->slow = 1;
    }
}

void green_attack(dg_entity_t *ent, void *data, tower_data_t *d,
    dg_array_t **entities)
{
        enemy_data_t *data_monster = NULL;
    tower_data_t *m = NULL;
    int monster_detection = 0;
    float distance = 0;

    if (!dg_strcmp(ent->name, "monster")) {
        data_monster = ((script_t *)dg_entity_get_component
            (ent, "script"))->data;
        m = ((tower_data_t *)data);
        distance = dg_square(d->pos->x - data_monster->pos->x)
            + dg_square(d->pos->y - data_monster->pos->y);
        monster_detection = (distance <= dg_square(d->radius)) ? 1 : 0;
        if (d->delay >= d->delay_max && monster_detection == 1)
            data_monster->poison = 1;
    }
}

void attack_tower(dg_entity_t *ent, void *data, tower_data_t *d,
    dg_array_t **entities)
{
    (d->id == 0 || d->id == 4) ? arrow_attack(ent, data, d, entities) : 0;
    (d->id == 1 || d->id == 5) ? canon_attack(ent, data, d, entities) : 0;
    (d->id == 2 || d->id == 6) ? blue_attack(ent, data, d, entities) : 0;
    (d->id == 3 || d->id == 7) ? green_attack(ent, data, d, entities) : 0;
}