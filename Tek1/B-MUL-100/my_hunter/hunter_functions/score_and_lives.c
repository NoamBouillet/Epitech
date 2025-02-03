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
#include "../structs.h"
#include "../my_hunter.h"
#include <time.h>

sfTexture *choose_texture(int nb_lives, int nb_heart)
{
    sfTexture *texture;

    if (nb_lives < nb_heart)
        texture = sfTexture_createFromFile("assets/brokenheart.png", NULL);
    else
        texture = sfTexture_createFromFile("assets/heart.png", NULL);
    return texture;
}

void display_lives(window_t *window, int nb)
{
    sfSprite *first_life = sfSprite_create();
    sfSprite *second_life = sfSprite_create();
    sfSprite *third_life = sfSprite_create();
    sfVector2f first = {1550, 30};
    sfVector2f second = {1670, 30};
    sfVector2f third = {1790, 30};

    sfSprite_setTexture(first_life, choose_texture(nb, 1), sfTrue);
    sfSprite_setPosition(first_life, first);
    sfRenderWindow_drawSprite(window->window, first_life, NULL);
    sfSprite_setTexture(second_life, choose_texture(nb, 2), sfTrue);
    sfSprite_setPosition(second_life, second);
    sfRenderWindow_drawSprite(window->window, second_life, NULL);
    sfSprite_setTexture(third_life, choose_texture(nb, 3), sfTrue);
    sfSprite_setPosition(third_life, third);
    sfRenderWindow_drawSprite(window->window, third_life, NULL);
}

static void check_window_close(window_t *window
    , sfClock *pause_clock, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
}

static void set_over(window_t *window)
{
    char *over = "GAME OVER";
    sfText *scoreText = sfText_create();
    sfClock *pause_clock;
    sfEvent event;

    sfText_setFont(scoreText, window->font);
    sfText_setCharacterSize(scoreText, 150);
    sfText_setFillColor(scoreText, sfWhite);
    sfText_setPosition(scoreText, (sfVector2f){245, 400});
    sfText_setString(scoreText, over);
    sfRenderWindow_drawText(window->window, scoreText, NULL);
    sfRenderWindow_display(window->window);
    pause_clock = sfClock_create();
    while (sfTime_asSeconds(sfClock_getElapsedTime(pause_clock)) < 3.0f)
        check_window_close(window, pause_clock, event);
    sfClock_destroy(pause_clock);
    sfText_destroy(scoreText);
}

int check_lives(window_t *window, stats_t *stats)
{
    if (stats->lives <= 0) {
        set_over(window);
        return 1;
    }
    display_lives(window, stats->lives);
    return 0;
}

void display_score(window_t *window, stats_t *stats)
{
    char *base = "Score: ";
    char *number = turns_int_to_string(stats->score);
    size_t len = my_strlen(base) + my_strlen(number) + 1;
    char *scoreString = malloc(len);
    sfText *scoreText = sfText_create();

    sfText_setFont(scoreText, window->font);
    sfText_setCharacterSize(scoreText, 60);
    sfText_setFillColor(scoreText, sfWhite);
    sfText_setPosition(scoreText, (sfVector2f){30, 30});
    my_strcpy(scoreString, base);
    my_strcat(scoreString, number);
    sfText_setString(scoreText, scoreString);
    sfRenderWindow_drawText(window->window, scoreText, NULL);
    free(scoreString);
    free(number);
    sfText_destroy(scoreText);
}
