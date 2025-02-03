/*
** EPITECH PROJECT, 2024
** sprites
** File description:
** sprites_creation
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../structs.h"
#include "../my_hunter.h"
#include <stdbool.h>
#include <math.h>

sprite_t *initialize_sprite(window_t *window)
{
    sfIntRect rect = {0, 0, 150, 150};
    int random = rand() % 2;
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (random == 0) {
        sprite->sprite = sfSprite_create();
        sprite->texture = window->skeletons;
    } else {
        sprite->sprite = sfSprite_create();
        sprite->texture = window->zombies;
    }
    sprite->rect = rect;
    sprite->position.x = -150;
    sprite->position.y = rand() % 751 + 100;
    sprite->shooted = 0;
    sprite->clock = sfClock_create();
    sprite->next = NULL;
    return sprite;
}

void add_sprite_to_list(sprite_t **sprite_list, window_t window)
{
    sprite_t *new_sprite = initialize_sprite(&window);
    sprite_t *current;

    if (*sprite_list == NULL) {
        *sprite_list = new_sprite;
        return;
    }
    current = *sprite_list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_sprite;
}

void manage_sprites(window_t *window, sprite_t **sprite_list
    , sfClock *clock, stats_t *stats)
{
    static float delay = 0;
    double malus_score = (stats->score * 0.01);
    float elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    if (elapsed_time > delay) {
        add_sprite_to_list(sprite_list, *window);
        if (stats->score > 40)
            malus_score = 0.4;
        delay = (rand() % 2) + 0.6 - malus_score;
        sfClock_restart(clock);
    }
}
