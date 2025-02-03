/*
** EPITECH PROJECT, 2024
** permissions
** File description:
** permissions
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
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

void print_sticky_bit(char *real_path)
{
    struct stat path_stat;

    stat(real_path, &path_stat);
    if (path_stat.st_mode & __S_ISVTX) {
        if (path_stat.st_mode & S_IXOTH)
            my_printf("t");
        else
            my_printf("T");
    } else {
        my_printf("%c", (path_stat.st_mode & S_IXOTH) ? 'x' : '-');
    }
}

int print_permissions(char *real_path)
{
    struct stat path_stat;

    if (stat(real_path, &path_stat) != 0) {
        write(2, "Error accessing path\n", 22);
        exit(84);
    }
    my_printf("%c", (path_stat.st_mode & S_IRUSR) ? 'r' : '-');
    my_printf("%c", (path_stat.st_mode & S_IWUSR) ? 'w' : '-');
    my_printf("%c", (path_stat.st_mode & S_IXUSR) ? 'x' : '-');
    my_printf("%c", (path_stat.st_mode & S_IRGRP) ? 'r' : '-');
    my_printf("%c", (path_stat.st_mode & S_IWGRP) ? 'w' : '-');
    my_printf("%c", (path_stat.st_mode & S_IXGRP) ? 'x' : '-');
    my_printf("%c", (path_stat.st_mode & S_IROTH) ? 'r' : '-');
    my_printf("%c", (path_stat.st_mode & S_IWOTH) ? 'w' : '-');
    print_sticky_bit(real_path);
    return 0;
}
