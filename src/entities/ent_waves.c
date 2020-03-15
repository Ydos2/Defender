/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** waves entities
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "general_data.h"

dg_entity_t *ent_wave(game_data_t *gd)
{
    dg_entity_t *entity = dg_entity_create("wave");

    dg_entity_add_component(entity, cpt_script(&scp_wave_init, &scp_wave_loop,
        &scp_wave_end, gd));
    return entity;
}