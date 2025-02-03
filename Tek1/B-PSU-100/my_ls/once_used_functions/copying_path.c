/*
** EPITECH PROJECT, 2024
** dash_l2
** File description:
** dash_l2
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
#include <pwd.h>
#include <unistd.h>
#include <linux/limits.h>

int copy_path(char *path, dir_t *dir_list, struct dirent *entry)
{
    my_strcpy(path, dir_list->path);
    my_strcat(path, "/");
    my_strcat(path, entry->d_name);
    return 0;
}
