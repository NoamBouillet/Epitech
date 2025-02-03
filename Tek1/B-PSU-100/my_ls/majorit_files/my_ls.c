/*
** EPITECH PROJECT, 2024
** my ls
** File description:
** replicates the ls function
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include "my.h"
#include "structs.h"
#include "ls_functions.h"
#include <stdbool.h>
#include <unistd.h>

int my_ls(int argc, char **argv)
{
    flags_t flags = {false, false, false, false, false, false, 0};
    dir_t *dir_list = NULL;

    if (search_for_flags(argc, argv, &flags) == 84)
        exit(84);
    if (create_list_dirs(argc, argv, &dir_list, flags) == 84) {
        free_list(dir_list);
        exit(84);
    }
    apply_flags(&dir_list, flags);
    return 0;
}
