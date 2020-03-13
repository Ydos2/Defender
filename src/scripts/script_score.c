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
#include "libmy.h"

typedef struct data {
    int *tracker;
    char *text;
    sfText *result;
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
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;
    char *str_tracker = my_itoa(*(data->tracker));
    int txt_len = my_strlen(data->text);
    int tracker_len = my_strlen(str_tracker);
    char *result = malloc(sizeof(char) * (txt_len + tracker_len + 1));

    for (int i = 0; i < txt_len; i++)
        result[i] = data->text[i];
    for (int i = 0; i < tracker_len; i++)
        result[txt_len + i] = str_tracker[i];
    result[txt_len + tracker_len] = '\0';
    sfText_setString(data->result, result);
    free(str_tracker);
}

void scp_score_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}