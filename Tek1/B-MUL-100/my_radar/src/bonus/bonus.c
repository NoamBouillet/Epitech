/*
** EPITECH PROJECT, 2025
** bonus
** File description:
** bonus functions
*/

#include "../include/my_radar.h"

void create_a_dragged_plane(bonus_t *bonus, planes_t **list_planes
    , parameters_t *params, sfEvent event)
{
    bonus->end = (sfVector2f){event.mouseButton.x, event.mouseButton.y};
    planes_t *plane = malloc(sizeof(planes_t));

    if (!plane)
        return;
    plane->is_crashed = 0;
    plane->current_pos = bonus->start;
    plane->direction = calculate_direction(bonus->start, bonus->end);
    plane->end_position = bonus->end;
    plane->delay = 0;
    plane->sprite = sfSprite_create();
    plane->hitbox = get_hitbox_square();
    plane->speed = 5;
    set_rotation_plane(plane);
    sfSprite_setTexture(plane->sprite, params->plane, false);
    bonus->is_dragged = 0;
    plane->next = *list_planes;
    *list_planes = plane;
}

void show_F3(bonus_t *bonus, parameters_t *params)
{
    char *nb_collisions = turns_int_to_string(bonus->number_collisions);
    char *complete_char = my_strcat
        ("Updated F3 of the running my_radar:\nNumber of collisions since beginning: "
            , nb_collisions);

    sfText_setString(bonus->f3, complete_char);
    sfRenderWindow_drawText(params->window, bonus->f3, NULL);
    free(nb_collisions);
    free(complete_char);
}