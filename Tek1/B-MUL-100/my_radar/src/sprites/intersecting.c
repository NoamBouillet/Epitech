/*
** EPITECH PROJECT, 2025
** intersecting
** File description:
** checks intersection between planes
*/

#include "../include/my_radar.h"

int is_intersecting_squares(planes_t *c1, planes_t *c2)
{
    sfVector2f position = c1->current_pos;
    sfVector2f position2 = c2->current_pos;
    float size = 20;

    if (position.x < position2.x + size &&
        position.x + size > position2.x &&
        position.y < position2.y + size &&
        position.y + size > position2.y)
        return 1;
    return 0;
}

void check_to_destroy(planes_t *to_compare
    , planes_t *planes, float seconds, bonus_t *bonus)
{
    while (to_compare != NULL) {
        if (to_compare->next == planes->next ||
            to_compare->delay >= seconds || to_compare->is_crashed) {
            to_compare = to_compare->next;
            continue;
        }
        if (is_intersecting_squares(to_compare, planes)) {
            bonus->number_collisions++;
            planes->is_crashed = 1;
            to_compare->is_crashed = 1;
        }
        to_compare = to_compare->next;
    }
}

int is_under_tower(planes_t *plane, towers_t *tower)
{
    sfVector2f position = plane->current_pos;
    float plane_radius = 10;
    sfVector2f tower_position = {0, 0};
    float tower_radius = 0;

    while (tower != NULL) {
        tower_position = tower->position;
        tower_radius = tower->radius;
        if ((pow((position.x - tower_position.x), 2) +
            pow((position.y - tower_position.y), 2)) <=
            pow((plane_radius + tower_radius), 2))
            return 1;
        tower = tower->next;
    }
    return 0;
}

void check_intersecting(planes_t **plane_list
    , towers_t *tower, float seconds, bonus_t *bonus)
{
    planes_t *planes = *plane_list;
    planes_t *to_compare = *plane_list;

    while (planes != NULL) {
        if (is_under_tower(planes, tower) == 1 ||
            planes->delay >= seconds || planes->is_crashed) {
            planes = planes->next;
            continue;
        }
        check_to_destroy(to_compare, planes, seconds, bonus);
        planes = planes->next;
    }
}
