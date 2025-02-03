/*
** EPITECH PROJECT, 2025
** towers
** File description:
** initialize towers by reading the filepath
*/

#include "../include/my_radar.h"

sfCircleShape *get_tower_hitbox(towers_t *tower)
{
    sfCircleShape *hitbox = sfCircleShape_create();
    int radius = tower->radius;
    sfVector2f position = tower->position;
    sfVector2f circle_box = {position.x - radius, position.y - radius};

    sfCircleShape_setPosition(hitbox, circle_box);
    sfCircleShape_setRadius(hitbox, radius);
    sfCircleShape_setFillColor(hitbox, sfTransparent);
    sfCircleShape_setOutlineColor(hitbox, sfGreen);
    sfCircleShape_setOutlineThickness(hitbox, 4);
    return hitbox;
}

towers_t *add_towers_to_list(towers_t *towers,
    parameters_t params, char **data_planes)
{
    towers_t *new_tower = malloc(sizeof(towers_t));
    sfVector2f coordinates = {str_toi(data_planes[1]),
        str_toi(data_planes[2])};
    sfVector2f coord_hitbox = {coordinates.x + 32,
        coordinates.y + 75};
    sfSprite *sprite = sfSprite_create();

    if (!sprite || !new_tower)
        return NULL;
    new_tower->radius = str_toi(data_planes[3]) * 8;
    new_tower->sprite = sprite;
    new_tower->position = coord_hitbox;
    new_tower->texture = params.tower;
    new_tower->hitbox = get_tower_hitbox(new_tower);
    new_tower->next = towers;
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, true);
    sfSprite_setPosition(new_tower->sprite, coordinates);
    return new_tower;
}
