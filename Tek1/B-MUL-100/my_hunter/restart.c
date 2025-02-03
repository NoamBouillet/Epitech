/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "structs.h"
#include "my_hunter.h"
#include <time.h>
#include <unistd.h>

void run_window(window_t *window, sprite_t **first
    , stats_t *stats, sfClock *sprite_clock)
{
    while (sfRenderWindow_isOpen(window->window)) {
        handle_events(window, first, stats);
        if (draw_frame(window, first, stats) == 0) {
            manage_sprites(window, first, sprite_clock, stats);
        } else {
            break;
        }
    }
}

void restart_game(window_t *window, menu_t *menu)
{
    stats_t stats;
    sfClock *sprite_clock;
    sprite_t *first;

    do {
        stats = (stats_t){0, 3};
        sprite_clock = sfClock_create();
        first = initialize_sprite(window);
        crosshair(*window);
        if (!display_menu(window->window, window->background, menu)) {
            free_all_sprites(first);
            sfClock_destroy(sprite_clock);
            return;
        }
        run_window(window, &first, &stats, sprite_clock);
        sfClock_destroy(sprite_clock);
        free_all_sprites(first);
    } while (stats.lives == 0 && sfRenderWindow_isOpen(window->window));
}
