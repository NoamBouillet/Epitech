/*
** EPITECH PROJECT, 2025
** sprites_updates
** File description:
** updating position, showing sprites
*/

#include "../include/my_radar.h"

int is_arrived_to_destination(planes_t *sprite)
{
    int x_separation = sprite->current_pos.x - sprite->end_position.x;
    int y_separation = sprite->current_pos.y - sprite->end_position.y;

    if ((x_separation > -20 && x_separation < 20) &&
        (y_separation > -20 && y_separation < 20))
            return 1;
    return 0;
}

void show_sprites(planes_t **list_planes, parameters_t params
    , towers_t *tower, float seconds)
{
    planes_t *planes = *list_planes;

    while (tower != NULL) {
        sfRenderWindow_drawSprite(params.window, tower->sprite, NULL);
        tower = tower->next;
    }
    for (; planes != NULL; planes = planes->next) {
        if (planes->delay > seconds) {
            continue;
        }
        sfRenderWindow_drawSprite(params.window, planes->sprite, NULL);
    }
}

int update_sprite(planes_t *sprite)
{
    int pose_x = sprite->current_pos.x;
    int pose_y = sprite->current_pos.y;
    float speed = sprite->speed;

    if (pose_x > 1920 || pose_x < 0 || pose_y < 0
        || sprite->is_crashed == 1 || pose_y > 1080 ||
        is_arrived_to_destination(sprite))
        return -1;
    sprite->current_pos.x += sprite->direction.x * (speed);
    sprite->current_pos.y += sprite->direction.y * (speed);
    sfSprite_setPosition(sprite->sprite, (sfVector2f)
        {sprite->current_pos.x + 10, sprite->current_pos.y + 10});
    return 0;
}

void delete_node(planes_t **previous_sprite
    , planes_t **begin, planes_t **current_sprite)
{
    planes_t *to_free = *current_sprite;

    if (*previous_sprite == NULL) {
        *begin = to_free->next;
        *current_sprite = *begin;
    } else {
        (*previous_sprite)->next = to_free->next;
        *current_sprite = to_free->next;
    }
    sfSprite_destroy(to_free->sprite);
    sfRectangleShape_destroy(to_free->hitbox);
    free(to_free);
}

void run_sprites(planes_t **begin, float seconds)
{
    planes_t *current_sprite = *begin;
    planes_t *previous_sprite = NULL;

    while (current_sprite != NULL) {
        if (current_sprite->delay > seconds) {
            previous_sprite = current_sprite;
            current_sprite = current_sprite->next;
            continue;
        }
        if (update_sprite(current_sprite) == -1) {
            delete_node(&previous_sprite, begin, &current_sprite);
        } else {
            previous_sprite = current_sprite;
            current_sprite = current_sprite->next;
        }
    }
}
