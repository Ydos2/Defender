/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the ecs objects
*/

#ifndef ECS_H_
#define ECS_H_

#include "libdragon.h"

// background_menu.c
dg_entity_t *ent_sprite_create(int id);

// text_menu.c
dg_entity_t *entity_text_create(void);

// cpt_button.c
dg_entity_t *ent_button(sfVector2f pos, char *text
    , void (*action)(dg_window_t *));

// cpt_button.c
dg_component_t *cpt_scale(float x, float y);

// cpt_box_collider.c
dg_component_t *cpt_box_collider(float left, float top
    , float height, float width);

// cpt_action.c
dg_component_t *component_action_create(void (*action)(dg_window_t *));

void system_player_control(dg_entity_t *, dg_window_t *, dg_array_t **, sfTime);

// scenes
dg_scene_t *scene_game(void);
dg_scene_t *scene_map_1(void);

// dg_cpt_spritesheet.c
dg_component_t *dg_cpt_spritesheet(int id);
void dg_sys_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// cpt_text.c
dg_component_t *component_text_create(int scale,
    char *content);
void system_display_text(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// sys_button.c
void sys_button(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// cpt_sound.c
dg_component_t *cpt_sound_create(char *path);
void sound_play(sfMusic *sound);

// ent_music.c
dg_entity_t *ent_music(char *path);

#endif