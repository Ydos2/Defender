/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** cpt_game_data
*/

#include <stdlib.h>
#include "dg_component.h"
#include "ecs.h"
#include "general_data.h"

static void component_destroy(void *data)
{
    game_data_t *game_data = (game_data_t *)data;

    free(game_data);
}

dg_component_t *cpt_game_data(void)
{
    void (*destroy)(void *) = &component_destroy;
    dg_component_t *component = 0;

    game_data_t *game_data = malloc(sizeof(game_data_t));
    game_data->build_id = -1;
    game_data->can_spawn_tower = 1;
    game_data->money = 10;
    component = dg_component_create("game_data", game_data, destroy);
    return component;
}