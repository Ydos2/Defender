/*
** EPITECH PROJECT, 2020
** text_menu
** File description:
** text_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

dg_entity_t *ent_score(sfVector2f pos, int scale, char *text, int *number)
{
    dg_entity_t *ctext = dg_entity_create("text");
    void *idata[2] = {number, text};

    dg_entity_add_component(ctext, dg_cpt_pos(pos.x, pos.y));
    dg_entity_add_component(ctext, cpt_text((sfVector2f){0, 0}, scale, text));
    dg_entity_add_component(ctext, cpt_script(&scp_score_init, scp_score_loop,
        scp_score_end, idata));
    return ctext;
}
