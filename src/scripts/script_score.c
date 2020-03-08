/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** score script
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

typedef struct data {
    int *tracker;
    char *text;
} data_t;

void *scp_score_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));

    data->tracker = (int *)idata[0];
    data->text = (char *)idata[1];
    return data;
}

void scp_score_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{

}

void scp_score_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}