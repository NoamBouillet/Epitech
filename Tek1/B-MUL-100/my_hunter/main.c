/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** main
*/

#include "my_hunter.h"

int main(int argc, char **argv, char **env)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return dash_h();
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'D' && env[i][1] == 'I' && argc == 1)
            return my_hunter();
    }
    return 84;
}
