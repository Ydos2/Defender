/*
** EPITECH PROJECT, 2020
** tower_data
** File description:
** tower_data
*/

#ifndef TOWER_DATA_H_
#define TOWER_DATA_H_

typedef struct tower_data
{
    float radius;
    sfVector2f *pos;
    dg_entity_t *entity;
    sfCircleShape *circle;
    int delay_max;
    int delay;
    int id;
    int stat;
    dg_entity_t *buttons[2];
} tower_data_t;

#endif /* !TOWER_DATA_H_ */