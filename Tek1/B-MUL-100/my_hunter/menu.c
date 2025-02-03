/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** menu
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "structs.h"
#include "my_hunter.h"
#include <time.h>
#include <unistd.h>


menu_t create_menu(sfFont *font)
{
    menu_t menu;
    sfVector2f button_size = {400, 100};
    sfVector2f play_position = {760, 400};
    sfVector2f quit_position = {760, 550};

    menu.play_button = sfRectangleShape_create();
    sfRectangleShape_setSize(menu.play_button, button_size);
    sfRectangleShape_setFillColor(menu.play_button
        , sfColor_fromRGB(100, 6, 6));
    sfRectangleShape_setPosition(menu.play_button, play_position);
    menu.quit_button = sfRectangleShape_create();
    sfRectangleShape_setSize(menu.quit_button, button_size);
    sfRectangleShape_setFillColor(menu.quit_button
        , sfColor_fromRGB(100, 6, 6));
    sfRectangleShape_setPosition(menu.quit_button, quit_position);
    menu.play_text = create_text(font, "PLAY", 50);
    sfText_setPosition(menu.play_text, (sfVector2f){855, 420});
    menu.quit_text = create_text(font, "QUIT", 50);
    sfText_setPosition(menu.quit_text, (sfVector2f){855, 570});
    return menu;
}

static int get_event_type(sfRenderWindow *window, menu_t *menu)
{
    sfFloatRect play_bounds;
    sfVector2i mouse_pos;
    sfVector2f world_pos;
    sfFloatRect quit_bounds;

    mouse_pos = sfMouse_getPositionRenderWindow(window);
    world_pos = sfRenderWindow_mapPixelToCoords(window, mouse_pos, NULL);
    play_bounds = sfRectangleShape_getGlobalBounds(menu->play_button);
    if (sfFloatRect_contains(&play_bounds, world_pos.x, world_pos.y)) {
        return 1;
    }
    quit_bounds = sfRectangleShape_getGlobalBounds(menu->quit_button);
    if (sfFloatRect_contains(&quit_bounds, world_pos.x, world_pos.y)) {
        return 0;
    }
    return 2;
}

int check_events(sfEvent event, sfRenderWindow *window, menu_t *menu)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return 0;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        switch (get_event_type(window, menu)) {
        case 1:
            return 1;
        case 0:
            return 0;
        }
    }
    return -1;
}

int actualize_window(sfRenderWindow *window, menu_t *menu
    , sfTexture *background, sfSprite *bg_sprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        switch (check_events(event, window, menu)) {
        case 1:
            return 1;
        case 0:
            return 0;
        }
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg_sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->play_button, NULL);
    sfRenderWindow_drawRectangleShape(window, menu->quit_button, NULL);
    sfRenderWindow_drawText(window, menu->play_text, NULL);
    sfRenderWindow_drawText(window, menu->quit_text, NULL);
    sfRenderWindow_display(window);
}

int display_menu(sfRenderWindow *window, sfTexture *background, menu_t *menu)
{
    sfSprite *bg_sprite = sfSprite_create();

    sfSprite_setTexture(bg_sprite, background, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        if (actualize_window(window, menu, background, bg_sprite) == 1)
            return 1;
        if (actualize_window(window, menu, background, bg_sprite) == 0)
            return 0;
    }
    return 0;
}

void cleanup_menu(menu_t *menu)
{
    sfRectangleShape_destroy(menu->play_button);
    sfRectangleShape_destroy(menu->quit_button);
    sfText_destroy(menu->play_text);
    sfText_destroy(menu->quit_text);
}
