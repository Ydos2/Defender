/*
** EPITECH PROJECT, 2020
** scene_how_to_play
** File description:
** scene_how_to_play
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

static void go_to_map(dg_window_t *w)
{
    dg_scene_t *new_scene = 0;

    dg_scene_manager_add_scene(scene_main_menu());
    new_scene = dg_scene_manager_get_scene("main_menu");
    new_scene->run = 1;
    new_scene->display = 1;
    dg_scene_manager_remove("how_to_play");
}

static void go_to_quit(dg_window_t *w)
{
    w->quit = 1;
}

void text_add_ent(dg_scene_t *scene)
{
    dg_scene_add_ent(scene, ent_text(300, 100, 200, "TDDDDD"));
    dg_scene_add_ent(scene, ent_text(100, 600, 50,
        "This game is tower defense. So you will face waves of "));
    dg_scene_add_ent(scene, ent_text(100, 650, 50,
        "monsters that will want to destroy your castle, to stop them you "));
    dg_scene_add_ent(scene, ent_text(100, 700, 50,
        "have to place towers with the tower creation menu.\n"));
    dg_scene_add_ent(scene, ent_text(100, 750, 50,
        "Each tower is different and has a different price too.\n"));
    dg_scene_add_ent(scene, ent_text(100, 800, 50,
        "You can improve and sell them by clicking on them.\n"));
    dg_scene_add_ent(scene, ent_text(100, 850, 50,
        "PS : Towers can\'t be built next to each other.\n"));
    dg_scene_add_ent(scene, ent_text(100, 900, 50,
        "The game stops if the castle reaches 0 of life."));
    dg_scene_add_ent(scene, ent_text(1100, 150, 150, "How to play"));
}

dg_scene_t *scene_how_to_play(void)
{
    dg_scene_t *scene = dg_scene_create("how_to_play");

    dg_scene_add_ent(scene, ent_button
        ((sfVector2f){1100, 800}, 100, "Return", &go_to_map));
    dg_scene_add_ent(scene, ent_music("./sound/menu_song.ogg"));
    dg_scene_add_ent(scene, ent_sprite(0, 1, 0, 0));
    text_add_ent(scene);
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_button, 0));
    scene->run = 1;
    scene->display = 1;
    return scene;
}