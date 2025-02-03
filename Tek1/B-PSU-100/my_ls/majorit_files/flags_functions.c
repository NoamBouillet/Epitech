/*
** EPITECH PROJECT, 2024
** apply_flags
** File description:
** calls the flags
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

int apply_flags(dir_t **dir, flags_t flags)
{
    my_sort_list_alp(dir);
    if (flags.t == true)
        my_sort_list(dir);
    if (flags.r == true)
        my_rev_list(dir);
    if (flags.l == true)
        return dash_l(flags, *dir);
    handle_flags_and_print(flags, *dir);
    return 0;
}
