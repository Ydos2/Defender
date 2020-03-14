/*
** EPITECH PROJECT, 2020
** ent_build menu
** File description:
** ent_slot
*/

#include <stdlib.h>
#include "libdragon.h"
#include "script.h"
#include "ecs.h"

dg_entity_t *ent_build_menu(dg_entity_t *camera, dg_scene_t *scene)
{
    dg_entity_t *slot = dg_entity_create("build_menu");
    void *idata[3] = {slot, camera, scene};

    dg_entity_add_component(slot, cpt_script(&scp_build_menu_init,
        scp_build_menu_loop, scp_build_menu_end, idata));
    dg_entity_add_component(slot, cpt_spritesheet(8));
    return slot;
}