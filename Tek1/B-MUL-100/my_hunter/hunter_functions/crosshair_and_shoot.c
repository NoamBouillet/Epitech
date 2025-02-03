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

static void is_clicked(sprite_t *current
    , sfVector2f mouse_world_pos, stats_t *stats)
{
    sfFloatRect bounds;

    while (current != NULL) {
        bounds = sfSprite_getGlobalBounds(current->sprite);
        if (sfFloatRect_contains(&bounds
            , mouse_world_pos.x, mouse_world_pos.y)) {
            current->shooted = 1;
            stats->score++;
        }
        current = current->next;
    }
}

void check_sprite_click(sprite_t *sprites
    , sfRenderWindow *window, sfEvent event, stats_t *stats)
{
    sfVector2i mouse_pos;
    sfVector2f mouse_world_pos;
    sprite_t *current;

    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        mouse_world_pos = sfRenderWindow_mapPixelToCoords
            (window, mouse_pos, NULL);
        current = sprites;
        is_clicked(current, mouse_world_pos, stats);
    }
}

void crosshair(window_t window)
{
    sfImage *cursor = sfImage_createFromFile("assets/crosshair.png");
    sfVector2u size = sfImage_getSize(cursor);
    sfCursor *crosshair = sfCursor_createFromPixels(
        sfImage_getPixelsPtr(cursor), size, (sfVector2u){50, 50});

    sfRenderWindow_setMouseCursor(window.window, crosshair);
}
