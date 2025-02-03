/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** loading
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../structs.h"
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../my_hunter.h"

sfRenderWindow* create_window(unsigned int width, unsigned int height
    , unsigned int bitsPerPixel)
{
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();

    return sfRenderWindow_create(video_mode, "window", sfDefaultStyle, NULL);
}

sfSprite* create_sprite(sfTexture* texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfText* create_text(sfFont* font, const char *string, unsigned int size)
{
    sfText *text = sfText_create();

    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return text;
}

sfMusic* play_music(const char *filename)
{
    sfMusic *music = sfMusic_createFromFile(filename);

    if (music != NULL) {
        sfMusic_setLoop(music, sfTrue);
        sfMusic_play(music);
    }
    return music;
}

int draw_frame(window_t *window, sprite_t **first, stats_t *stats)
{
    sfSprite_setTexture(window->sprite, window->background, sfTrue);
    sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
    if (check_lives(window, stats) == 1) {
        sfRenderWindow_display(window->window);
        return 1;
    }
    display_score(window, stats);
    *first = run_sprites(first, window, stats);
    sfRenderWindow_display(window->window);
    return 0;
}
