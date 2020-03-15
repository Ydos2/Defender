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

static void load_tower(void)
{
    dg_ressources_add_spritesheet("./img/tower.png", 64, 64);
    dg_ressources_add_spritesheet("./img/arrow_tower.png", 64, 64);
    dg_ressources_add_spritesheet("./img/blue_magic_tower.png", 64, 64);
    dg_ressources_add_spritesheet("./img/green_magic_tower.png", 64, 64);
    dg_ressources_add_spritesheet("./img/canon_tower_2.png", 64, 64);
    dg_ressources_add_spritesheet("./img/arrow_tower_2.png", 64, 64);
    dg_ressources_add_spritesheet("./img/blue_magic_tower_2.png", 64, 64);
    dg_ressources_add_spritesheet("./img/green_magic_tower2.png", 64, 64);
}

static void load_slot(void)
{
    dg_ressources_add_spritesheet("./img/slot_arrow.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_canon.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_ice.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_poison.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_up_arrow.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_up_canon.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_up_ice.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_up_poison.png", 220, 220);
    dg_ressources_add_spritesheet("./img/slot_delete.png", 220, 220);
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
    dg_ressources_add_spritesheet("./img/build_menu.png", 2000, 100);
    dg_ressources_add_spritesheet("./img/bullet.png", 10, 10);
    dg_ressources_add_spritesheet("./img/castle.png", 354, 448);
    load_tower();
    load_slot();
}