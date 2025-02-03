/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** sprites_updates
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../structs.h"
#include <SFML/Window.h>
#include <SFML/System.h>

static void change_sprite_position(float seconds, sprite_t *sprite)
{
    if (seconds > 0.2) {
        if (sprite->rect.left >= 600) {
            sprite->rect.left = 0;
        } else
            sprite->rect.left += 150;
        sfClock_restart(sprite->clock);
    }
}

int update_sprite(sprite_t *sprite, window_t *window, stats_t *stats)
{
    sfTime time = sfClock_getElapsedTime(sprite->clock);
    float seconds = sfTime_asSeconds(time);

    if (sprite->position.x > 1800)
        stats->lives--;
    if (sprite->position.x > 1800 || sprite->shooted == 1)
        return -1;
    sprite->position.x += stats->score * 0.1 + 7.5;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    change_sprite_position(seconds, sprite);
    sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
    return 0;
}

void free_all_sprites(sprite_t *begin)
{
    sprite_t *tmp;

    while (begin != NULL) {
        tmp = begin->next;
        free(begin);
        begin = tmp;
    }
}

static void delete_node(sprite_t **previous_sprite
    , sprite_t **begin, sprite_t **current_sprite)
{
    sprite_t *to_free = *current_sprite;

    if (*previous_sprite == NULL) {
        *begin = to_free->next;
        *current_sprite = *begin;
    } else {
        (*previous_sprite)->next = to_free->next;
        *current_sprite = to_free->next;
    }
    sfSprite_destroy(to_free->sprite);
    sfClock_destroy(to_free->clock);
    free(to_free);
}

sprite_t *run_sprites(sprite_t **begin, window_t *window, stats_t *stats)
{
    sprite_t *current_sprite = *begin;
    sprite_t *previous_sprite = NULL;

    while (current_sprite != NULL) {
        if (update_sprite(current_sprite, window, stats) == -1) {
            delete_node(&previous_sprite, begin, &current_sprite);
        } else {
            previous_sprite = current_sprite;
            current_sprite = current_sprite->next;
        }
    }
    return *begin;
}
