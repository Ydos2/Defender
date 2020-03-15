/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script castle
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "script.h"

typedef struct data {
    game_data_t *game_data;
} data_t;

void *scp_castle_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));

    data->game_data = dg_entity_get_component(NULL, "game_data");
    return data;
}

void scp_castle_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);
}

void scp_castle_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}