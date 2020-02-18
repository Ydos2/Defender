/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include <stdlib.h>
#include "libdragon.h"

void *dg_init(dg_window_t *window, void *import)
{
    dg_scene_manager_create();
    return 0;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    sfRenderWindow_clear(w->window, sfBlack);
    dg_scene_manager_update(w, dt);
    return 0;
}

void dg_end(void *var, int id)
{
    dg_scene_manager_destroy();
    dg_ressources_destroy();
}

int main(int argc, char **argv)
{
    return dg_play((sfVector2u){1920, 1080}, "Defender", 0, NULL);
}
