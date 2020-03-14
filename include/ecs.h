/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the ecs objects
*/

#ifndef ECS_H_
#define ECS_H_

#include "libdragon.h"

// scenes
dg_scene_t *scene_game(void);
dg_scene_t *scene_main_menu(void);
dg_scene_t *scene_escape_menu(void);
dg_scene_t *scene_endless_waves(void);

// entities
dg_entity_t *ent_music(char *path);
dg_entity_t *ent_sprite(int id, float scale, float x, float y);
dg_entity_t *ent_text(int x, int y, int scale, char *text);
dg_entity_t *ent_button(sfVector2f pos, int size, char *text
    , void (*action)(dg_window_t *));
dg_entity_t *ent_monster(sfVector2f pos, int id, float health);
dg_entity_t *ent_path(sfVector2f *vs);
dg_entity_t *ent_slot(sfVector2f pos, sfVector2f size
    , void (*action)(dg_entity_t *, dg_window_t *,
    dg_array_t **, sfTime));
dg_entity_t *ent_map(int id, float scale, float x, float y);
dg_entity_t *ent_game_data(void);
dg_entity_t *ent_tower(sfVector2f pos, int id, float *radius, int delay);
dg_entity_t *ent_score(sfVector2f pos, int scale, char *text, int *number);

// components
dg_component_t *cpt_action(void (*action)(dg_window_t *));
dg_component_t *cpt_text(sfVector2f pos, int scale, char *content);
dg_component_t *cpt_scale(float x, float y);
dg_component_t *cpt_box_collider(float left, float top
    , float height, float width);
dg_component_t *cpt_spritesheet(int id);
dg_component_t *cpt_sound(char *path);
dg_component_t *cpt_tag(char *tag);
dg_component_t *cpt_path(sfVector2f *vs);
dg_component_t *cpt_path_follower(void);
dg_component_t *cpt_action_slot(void (*action)(dg_entity_t *, dg_window_t *,
    dg_array_t **, sfTime));
dg_component_t *cpt_subentity(void);
dg_component_t *cpt_game_data(void);
dg_component_t *cpt_build_id(int id);
dg_component_t *cpt_script(void *(*init)(void *), dg_sysf_t loop,
    void (*end)(void *), void *idata);

// systems
void sys_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_display_text(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_button(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_escape(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_follow_path(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_slot(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_camera(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_create_tower(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_tower_spawn_range(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_script(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_tower_attack(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// init
void init_img(void);
void build_menu(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// utilities
void sound_play(sfMusic *sound);

// monsters
void monster_basic(dg_entity_t *entity);

// towers
void tower_basic(dg_entity_t *entity);

#endif