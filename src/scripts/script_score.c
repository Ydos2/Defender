/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** score script
*/

#include <stdlib.h>
#include "libdragon.h"
#include "script.h"
#include "ecs.h"

typedef struct data {
    int *tracker;
    char *text;
    char *result;
} data_t;

void *scp_score_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_entity_t *entity = idata[2];

    data->tracker = (int *)idata[0];
    data->text = (char *)idata[1];
    data->result = dg_entity_get_component(entity, "text");
    return data;
}

void scp_score_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    data->result = data->text;
}

void scp_score_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}