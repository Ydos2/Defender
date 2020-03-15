/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the ecs objects
*/

#ifndef ECS_H_
#define ECS_H_

#include "libdragon.h"
#include "general_data.h"
#include "enemy_data.h"

// scenes
dg_scene_t *scene_game(void);
dg_scene_t *scene_main_menu(void);
dg_scene_t *scene_escape_menu(void);
dg_scene_t *scene_how_to_play(void);
dg_scene_t *scene_lose(void);

// entities
dg_entity_t *ent_music(char *path);
dg_entity_t *ent_sprite(int id, float scale, float x, float y);
dg_entity_t *ent_text(int x, int y, int scale, char *text);
dg_entity_t *ent_button(sfVector2f pos, int size, char *text
    , void (*action)(dg_window_t *));
dg_entity_t *ent_monster(sfVector2f pos, int id);
dg_entity_t *ent_path(sfVector2f *vs);
dg_entity_t *ent_path_bullet(sfVector2f *vs);
dg_entity_t *ent_slot(dg_array_t **entities, sfVector2f pos, int id, int price);
dg_entity_t *ent_map(int id, float scale, float x, float y);
dg_entity_t *ent_game_data(void);
dg_entity_t *ent_tower(dg_array_t **entities,
    sfVector2f pos, int id, int delay);
dg_entity_t *ent_score(sfVector2f pos, int scale, char *text, int *number);
dg_entity_t *ent_build_menu(dg_entity_t *camera, dg_scene_t *scene);
dg_entity_t *ent_bullet(sfVector2f *pos, enemy_data_t *m);
dg_entity_t *ent_wave(game_data_t *gd);
dg_entity_t *ent_castle(sfVector2f pos, game_data_t *gd);
dg_entity_t *ent_slot_delete(dg_array_t **entities,
    sfVector2f pos, dg_entity_t *tower, int price);

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
dg_component_t *cpt_path_bullet_follow(void);
dg_component_t *cpt_path_bullet(sfVector2f *vs);
dg_component_t *cpt_color(sfColor color);

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
void sys_lose(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_path_bullet(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// init
void init_img(void);
void set_build_id(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// utilities
void sound_play(sfMusic *sound);

// monsters
void monster_basic(dg_entity_t *entity);

// towers
void tower_basic(dg_entity_t *entity);

#endif