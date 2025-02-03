/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** main
*/

#include "include/my_radar.h"

int main(int argc, char **argv, char **env)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return dash_h();
    if (argc != 2)
        return 84;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp("DISPLAY=:0", env[i]) == 0
            || my_strcmp("DISPLAY=:1", env[i]) == 0)
            return my_radar(argv);
    }
    return 84;
}
