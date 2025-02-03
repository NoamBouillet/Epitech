/*
** EPITECH PROJECT, 2025
** timer
** File description:
** prints the timer texts
*/

#include "../include/my_radar.h"

void assign_text_properties(parameters_t *params)
{
    sfText_setFont(params->text_time, params->font);
    sfText_setCharacterSize(params->text_time, 30);
    sfText_setFillColor(params->text_time, sfWhite);
    sfText_setPosition(params->text_time, (sfVector2f){1765, 15});
}

void show_program_time(float seconds, parameters_t params)
{
    char *string_time = turns_int_to_string(seconds);

    sfText_setString(params.text_time, string_time);
    sfRenderWindow_drawText(params.window, params.text_time, NULL);
    free(string_time);
}
