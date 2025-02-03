/*
** EPITECH PROJECT, 2025
** keys_managing
** File description:
** events based on key changes
*/

#include "../include/my_radar.h"

int show_hitbox(planes_t **list_planes, parameters_t *params
    , towers_t *tower, float seconds)
{
    planes_t *planes = *list_planes;
    sfRectangleShape *hitbox = NULL;

    if (!planes)
        return 0;
    hitbox = planes->hitbox;
    if (!hitbox)
        return 84;
    for (; tower != NULL; tower = tower->next)
        sfRenderWindow_drawCircleShape(params->window, tower->hitbox, NULL);
    for (; planes != NULL; planes = planes->next) {
        if (planes->delay > seconds)
            continue;
        sfRectangleShape_setPosition(hitbox, (sfVector2f){
            planes->current_pos.x + 2, planes->current_pos.y + 1});
        sfRenderWindow_drawRectangleShape(params->window, hitbox,
            NULL);
    }
    return 0;
}

void add_speed(planes_t **list_planes)
{
    planes_t *planes = *list_planes;

    for (; planes != NULL; planes = planes->next) {
        planes->speed += 2;
    }
}

void delete_a_tower(towers_t **tower)
{
    towers_t *previous = NULL;
    towers_t *current = *tower;

    while (current != NULL && current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous)
            previous->next = current->next;
        else
            *tower = NULL;
        sfSprite_destroy(current->sprite);
        sfCircleShape_destroy(current->hitbox);
        free(current);
    }
}

static void power_to_tower(towers_t *tower)
{
    while (tower != NULL) {
        tower->radius += 3;
        sfCircleShape_setPosition(tower->hitbox,
            (sfVector2f){tower->position.x - tower->radius
            , tower->position.y - tower->radius});
        sfCircleShape_setRadius(tower->hitbox, tower->radius);
        tower = tower->next;
    }
}

void change_params_if_key(parameters_t *params, sfEvent event
    , planes_t **list_planes, towers_t **tower)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyL)
            params->L_key = !params->L_key;
        if (event.key.code == sfKeyS)
            params->S_key = !params->S_key;
        if (event.key.code == sfKeyM)
            add_speed(list_planes);
        if (event.key.code == sfKeyR)
            delete_a_tower(tower);
        if (event.key.code == sfKeyP)
            power_to_tower(*tower);
    }
}

static void check_mouse_drag(parameters_t *params
    , sfEvent event, bonus_t *bonus, planes_t **list_planes)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        bonus->is_dragged = 1;
        bonus->start = (sfVector2f){event.mouseButton.x, event.mouseButton.y};
    }
    if (event.type == sfEvtMouseButtonReleased &&
        event.mouseButton.button == sfMouseLeft && bonus->is_dragged) {
        create_a_dragged_plane(bonus, list_planes, params, event);
    }
}

void handle_events(parameters_t *params, planes_t **list_planes
    , towers_t **tower, bonus_t *bonus)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(params->window, &event)) {
        if (event.type == sfEvtClosed || list_planes == NULL) {
            sfRenderWindow_close(params->window);
        }
        change_params_if_key(params, event, list_planes, tower);
        check_mouse_drag(params, event, bonus, list_planes);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF3)
            bonus->is_F3 = !bonus->is_F3;
    }
}
