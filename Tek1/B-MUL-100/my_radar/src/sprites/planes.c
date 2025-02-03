/*
** EPITECH PROJECT, 2025
** planes
** File description:
** initialize planes by reading the filepath
*/

#include "../include/my_radar.h"

sfVector2f calculate_direction(sfVector2f start, sfVector2f end)
{
    sfVector2f direction;
    float direction_x = end.x - start.x;
    float direction_y = end.y - start.y;
    float distance = sqrt(direction_x * direction_x +
        direction_y * direction_y);

    direction.x = direction_x / distance;
    direction.y = direction_y / distance;
    return direction;
}

sfRectangleShape *get_hitbox_square(void)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    if (!hitbox)
        return NULL;
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setSize(hitbox, (sfVector2f){17, 17});
    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox, 1);
    return hitbox;
}

void set_rotation_plane(planes_t *plane)
{
    sfSprite_setOrigin(plane->sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(plane->sprite,
        (sfVector2f){plane->current_pos.x + 10, plane->current_pos.y + 10});
    sfSprite_setRotation(plane->sprite,
        atan2f(plane->direction.y, plane->direction.x) * (180.0f / PI));
}

planes_t *initialize_sprite(parameters_t params, char **data_planes)
{
    sfVector2f start = {str_toi(data_planes[1]), str_toi(data_planes[2])};
    sfVector2f end = {str_toi(data_planes[3]), str_toi(data_planes[4])};
    planes_t *plane = malloc(sizeof(planes_t));

    if (!plane)
        return NULL;
    plane->is_crashed = 0;
    plane->current_pos = start;
    plane->direction = calculate_direction(start, end);
    plane->end_position = end;
    plane->delay = str_toi(data_planes[6]);
    plane->sprite = sfSprite_create();
    plane->hitbox = get_hitbox_square();
    plane->speed = str_toi(data_planes[5]) / 15;
    set_rotation_plane(plane);
    sfSprite_setTexture(plane->sprite, params.plane, false);
    return plane;
}

planes_t *add_planes_to_list(planes_t *plane_list,
    parameters_t params, char **data_planes)
{
    planes_t *new_plane = initialize_sprite(params, data_planes);

    new_plane->next = plane_list;
    return new_plane;
}
