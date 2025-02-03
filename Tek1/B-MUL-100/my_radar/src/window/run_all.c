/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** main functions, run the program
*/

#include "../include/my_radar.h"

int dash_h(void)
{
    write(1, "Air traffic simulation panel\n", 30);
    write(1, "USAGE\n", 7);
    write(1, "  ./my_radar [OPTIONS] path_to_script\n", 39);
    write(1, "  path_to_script   The path to the script file.\n", 49);
    write(1, "OPTIONS:\n", 10);
    write(1, "  -h print the usage and quit.\n", 32);
    write(1, "USER INTERACTIONS\n", 19);
    write(1, "  `L' key enable/disable hitboxes and areas.\n", 46);
    write(1, "  `S' key enable/disable sprites.\n", 35);
    write(1, "  `P' Power Up the towers.\n", 28);
    write(1, "  `M' Boosts the speed of the airplanes.\n", 42);
    write(1, "  `R' Deletes a tower.\n", 24);
    write(1, "  `F3' Shows data of the my_radar.\n", 36);
    return 0;
}

void draw_frame(planes_t **first, parameters_t params
    , towers_t *tower, bonus_t *bonus)
{
    sfRenderWindow_drawSprite(params.window, params.map, NULL);
    show_program_time(params.seconds, params);
    run_sprites(first, params.seconds);
    if (params.S_key) {
        show_sprites(first, params, tower, params.seconds);
    }
    if (params.L_key)
        show_hitbox(first, &params, tower, params.seconds);
    if (bonus->is_F3)
        show_F3(bonus, &params);
    sfRenderWindow_display(params.window);
}

void run_window(parameters_t params, planes_t **first
    , towers_t **tower, bonus_t *bonus)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    assign_text_properties(&params);
    while (sfRenderWindow_isOpen(params.window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        params.seconds = seconds;
        sfRenderWindow_clear(params.window, sfBlack);
        handle_events(&params, first, tower, bonus);
        if (*first == NULL)
            return;
        check_intersecting(first, *tower, seconds, bonus);
        draw_frame(first, params, *tower, bonus);
    }
}

int my_radar(char **argv)
{
    parameters_t params = create_structure();
    bonus_t bonus = {0};
    towers_t *list_towers = NULL;
    planes_t *first = NULL;

    if (!params.background || !params.plane || !params.font) {
        write(2, "wrong filepath specified or unable to load.", 44);
        return 84;
    }
    first = read_list_planes(argv[1], params, &list_towers);
    params.window = create_window();
    bonus = create_struct_bonus(params);
    if (!bonus.f3 || !params.window || first == (planes_t *)-1 || !list_towers)
        return 84;
    sfSprite_setTexture(params.map, params.background, true);
    sfRenderWindow_setFramerateLimit(params.window, 30);
    run_window(params, &first, &list_towers, &bonus);
    cleanup(params, list_towers, first, bonus);
    return 0;
}
