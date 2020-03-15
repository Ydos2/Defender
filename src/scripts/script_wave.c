/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** script wave
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"
#include "script.h"

typedef struct data {
    game_data_t *gd;
} data_t;

void *scp_wave_init(void *init_data)
{
    data_t *data = malloc(sizeof(data_t));

    data->gd = (game_data_t *)init_data;
    return data;
}

void scp_wave_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    void *data = ((script_t *)dg_entity_get_component(entity, "script"))->data;
    data_t *d = ((data_t *)data);
    dg_entity_t *monster = dg_get_entity(*entities, "monster");

    if (!monster) {
        d->gd->wave++;
        for (int i = 0; i < d->gd->wave * 3; i++) {
            dg_arr_add_end(entities, ent_monster(
                (sfVector2f){-10 - i * 70, 200}, 0));
        }
    }
}

void scp_wave_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}