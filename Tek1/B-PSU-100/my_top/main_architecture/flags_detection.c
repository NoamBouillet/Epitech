/*
** EPITECH PROJECT, 2024
** flags_detection
** File description:
** detects and stocks flags
*/

#include "my.h"
#include "structs.h"

static void change_struct_flag(char car, flags_t *flags, int i, char **argv)
{
    switch (car) {
        case 'U':
            flags->U = true;
            if (argv[i + 1] != NULL)
                flags->U_name = argv[i + 1];
            break;
        case 'd':
            if (argv[i + 1] != NULL)
                flags->d_seconds = strtof(argv[i + 1], '\0');
            break;
        case 'n':
            flags->n = true;
            if (argv[i + 1] != NULL)
                flags->n_iterations = strtod(argv[i + 1], '\0');
            break;
    }
}

static void add_flag(char **argv, int i, int j, flags_t *flags)
{
    char tab_flags[] = {'U', 'd', 'n'};

    for (int k = 0; tab_flags[k] != '\0'; k++) {
        if (argv[i][j] == tab_flags[k]) {
            change_struct_flag(tab_flags[k], flags, i, argv);
            return;
        }
    }
    flags->problem = 84;
    write(2, "invalid flag", 13);
}

int search_for_flags(int argc, char **argv, flags_t *flags)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            continue;
        for (int j = 1; j < (int)strlen(argv[i]) && ((i + 1) <= argc); j++) {
            add_flag(argv, i, j, flags);
        }
    }
    return flags->problem;
}
