/*
** EPITECH PROJECT, 2024
** structs hunter
** File description:
** structs
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef STRUCTS_H_
    #define STRUCTS_H_

typedef struct window {
    sfRenderWindow *window;
    sfTexture *background;
    sfTexture *skeletons;
    sfTexture *zombies;
    sfSprite *sprite;
    sfFont *font;
    sfMusic *music;
    sfClock *clock;
} window_t;

typedef struct stats {
    int score;
    int lives;
} stats_t;

typedef struct {
    sfRectangleShape *play_button;
    sfRectangleShape *quit_button;
    sfText *play_text;
    sfText *quit_text;
} menu_t;

typedef struct sprite_properties {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfClock *clock;
    int shooted;
    struct sprite_properties *next;
} sprite_t;

#endif /* !STRUCTS_H_ */
