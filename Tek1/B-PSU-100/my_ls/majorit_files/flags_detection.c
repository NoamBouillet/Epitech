/*
** EPITECH PROJECT, 2024
** flags_detection
** File description:
** detects and stocks flags
*/

#include "my.h"
#include "structs.h"
#include "ls_functions.h"
#include <stdlib.h>
#include <unistd.h>

static void change_struct_flag(char car, flags_t *flags)
{
    switch (car) {
            case 'r':
                flags->r = true;
                break;
            case 'R':
                flags->R = true;
                break;
            case 'l':
                flags->l = true;
                break;
            case 'a':
                flags->a = true;
                break;
            case 'd':
                flags->d = true;
                break;
            case 't':
                flags->t = true;
                break;
        }
}

static void add_flag(char **argv, int i, int j, flags_t *flags)
{
    char tab_flags[] = {'a', 'r', 'R', 'd', 'l', 't', '\0'};

    for (int k = 0; tab_flags[k] != '\0'; k++) {
        if (argv[i][j] == tab_flags[k]) {
            change_struct_flag(tab_flags[k], flags);
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
        for (int j = 1; j < my_strlen(argv[i]); j++) {
            add_flag(argv, i, j, flags);
        }
    }
    return flags->problem;
}
