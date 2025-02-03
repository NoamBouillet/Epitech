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
#include <unistd.h>

int dash_h(void)
{
    write(1,
    "Bienvenue dans \"HunterTale\"!\n"
    "Plongez dans un donjon sombre et inquiétant où des squelettes hargneux\n"
    "et des vampires affamés surgissent à chaque recoin.\n"
    "Armé de votre fidèle souris, testez vos réflexes dans ce shooter 2D\n"
    "frénétique à l'image de Duck Hunt.\n"
    "Le tout est porté par une ambiance musicale énergique et surréaliste\n"
    "rappelant l'intensité de Megalovania.\n"
    "Défiez les vagues ennemies, visez juste, et survivez dans ce chaos\n"
    "gothique pixelisé.\n"
    "Saurez-vous braver les ténèbres et battre les records ?\n\n",
    524);
    write(1, "Vous avez le droit à trois vies.\n", 35);
    write(1, "Tuez des monstres en leur cliquant dessus !\n\n", 46);
    write(1, "Usage: ./my_hunter [options]\n", 30);
    write(1, "Options:\n", 10);
    write(1, "    -h,   Montre le menu d'aide\n", 33);
    return 0;
}

void handle_events(window_t *window, sprite_t **sprites, stats_t *stats)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window->window);
        }
        check_sprite_click(*sprites, window->window, event, stats);
    }
}

void cleanup(window_t window, sprite_t *sprite)
{
    sfSprite_destroy(window.sprite);
    sfTexture_destroy(window.background);
    sfFont_destroy(window.font);
    sfClock_destroy(window.clock);
    if (window.music != NULL) {
        sfMusic_destroy(window.music);
    }
    free_all_sprites(sprite);
    sfRenderWindow_destroy(window.window);
}

window_t create_structure(void)
{
    sfRenderWindow *window = create_window(1920, 1080, 32);
    sfTexture *background = sfTexture_createFromFile
        ("assets/ruins.png", NULL);
    sfTexture *skeletons = sfTexture_createFromFile
        ("assets/skeletons.png", NULL);
    sfTexture *zombies = sfTexture_createFromFile("assets/vampire.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfFont *font = sfFont_createFromFile("assets/undertale.ttf");
    sfMusic *music = play_music("assets/megalovania.mp3");
    sfClock *clock = sfClock_create();
    window_t window_properties = {window, background, skeletons, zombies
    , sprite, font, music, clock};

    return window_properties;
}

int my_hunter(void)
{
    window_t window = create_structure();
    menu_t menu = create_menu(window.font);

    if (!window.background || !window.skeletons || !window.window
    || !window.zombies || !window.font || !window.music)
        return 84;
    sfRenderWindow_setFramerateLimit(window.window, 60);
    restart_game(&window, &menu);
    cleanup_menu(&menu);
    cleanup(window, NULL);
    return 0;
}
