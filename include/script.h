/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** script structure
*/

#include "libdragon.h"
#include "tower_data.h"

#ifndef SCRIPT_H_
#define SCRIPT_H_

typedef struct script
{
    void *(*init)(void *);
    dg_sysf_t loop;
    void (*end)(void *);
    void *data;
} script_t;

// score
void *scp_score_init(void *init_data);
void scp_score_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_score_end(void *data);

// tower
void *scp_tower_init(void *init_data);
void scp_tower_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_tower_end(void *data);
void init_tower_menu(tower_data_t *d);
void launch_tower_menu(tower_data_t *d);

// monster
void *scp_monster_init(void *init_data);
void scp_monster_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_monster_end(void *data);

// build menu
void *scp_build_menu_init(void *init_data);
void scp_build_menu_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_build_menu_end(void *data);

//built buttons
void *scp_build_buttons_init(void *init_data);
void scp_build_buttons_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_build_buttons_end(void *data);

// bullet
void *scp_bullet_init(void *init_data);
void scp_bullet_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_bullet_end(void *data);

// wave
void *scp_wave_init(void *init_data);
void scp_wave_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_wave_end(void *data);

// castle
void *scp_castle_init(void *init_data);
void scp_castle_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void scp_castle_end(void *data);

#endif /*SCRIPT_H_*/
