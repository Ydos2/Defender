/*
** EPITECH PROJECT, 2020
** init_img
** File description:
** init_img
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void load_map_solo(void)
{
    dg_ressources_add_spritesheet("./img/solo_map_01.png", 1920, 1080);
}

void init_img(void)
{
    dg_ressources_add_spritesheet("./img/background.png", 1920, 1080);
    dg_ressources_add_spritesheet("./img/button.png", 1104, 340);
    dg_ressources_add_spritesheet("./img/map-1.jpg", 1920, 1080);
    dg_ressources_add_spritesheet("./img/panel.png", 626, 417);
    dg_ressources_add_spritesheet("./img/monstre.png", 128, 128);
    dg_ressources_add_spritesheet("./img/slot.png", 220, 220);
    load_map_solo();
    dg_ressources_add_spritesheet("./img/tower.png", 64, 64);
}