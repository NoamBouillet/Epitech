/*
** EPITECH PROJECT, 2025
** window
** File description:
** csfml based functions, initializing and destroying the window
*/

#include "../include/my_radar.h"

sfRenderWindow* create_window(void)
{
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();

    return sfRenderWindow_create(video_mode, "window", sfDefaultStyle, NULL);
}

bonus_t create_struct_bonus(parameters_t params)
{
    sfVector2f start = {0, 0};
    sfVector2f end = {0, 0};
    int is_dragged = 0;
    int number_collisions = 0;
    int is_F3 = 0;
    sfText *f3 = sfText_create();
    bonus_t bonus = {start, end, is_dragged
        , number_collisions, f3, is_F3};

    sfText_setFont(bonus.f3, params.font);
    sfText_setCharacterSize(bonus.f3, 20);
    sfText_setFillColor(bonus.f3, sfWhite);
    sfText_setPosition(bonus.f3, (sfVector2f){30, 950});
    return bonus;
}

parameters_t create_structure(void)
{
    sfRenderWindow *window = NULL;
    sfTexture *background = sfTexture_createFromFile
        ("assets/background.jpg", NULL);
    sfSprite *map = sfSprite_create();
    sfTexture *plane = sfTexture_createFromFile
        ("assets/plane.png", NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.otf");
    sfTexture *tower = sfTexture_createFromFile("assets/tower.png", NULL);
    sfClock *clock = sfClock_create();
    int seconds = 0;
    int L_key = 1;
    int S_key = 1;
    parameters_t parameters = {window, background, map, plane,
        tower, clock, seconds, text, font, L_key, S_key};

    return parameters;
}

void cleanup_linked_lists(towers_t *towers, planes_t *planes)
{
    towers_t *towers_next = NULL;
    planes_t *planes_next = NULL;

    while (towers != NULL) {
        towers_next = towers->next;
        sfSprite_destroy(towers->sprite);
        sfCircleShape_destroy(towers->hitbox);
        free(towers);
        towers = towers_next;
    }
    while (planes != NULL) {
        planes_next = planes->next;
        sfSprite_destroy(planes->sprite);
        sfRectangleShape_destroy(planes->hitbox);
        free(planes);
        planes = planes_next;
    }
}

void cleanup(parameters_t params
    , towers_t *towers, planes_t *planes, bonus_t bonus)
{
    sfRenderWindow_destroy(params.window);
    sfTexture_destroy(params.tower);
    sfText_destroy(bonus.f3);
    sfText_destroy(params.text_time);
    sfFont_destroy(params.font);
    sfTexture_destroy(params.background);
    sfTexture_destroy(params.plane);
    sfSprite_destroy(params.map);
    sfClock_destroy(params.clock);
    cleanup_linked_lists(towers, planes);
}
