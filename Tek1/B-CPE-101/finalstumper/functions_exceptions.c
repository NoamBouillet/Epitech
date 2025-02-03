/*
** EPITECH PROJECT, 2024
** functions_exceptions.c
** File description:
** functions_exceptions
*/

#include "rush3.h"
#include <stdlib.h>

char *check_name2(char *buff, int length, int height)
{
    if (my_strcmp(rush_function4(length, height), buff) == 0)
        return "[rush1-4]";
    if (my_strcmp(rush_function5(length, height), buff) == 0)
        return "[rush1-5]";
    else
        return "none";
}

char *check_name(char *buff, int length, int height)
{
    if (my_strcmp(rush_function1(length, height), buff) == 0)
        return "[rush1-1]";
    if (my_strcmp(rush_function2(length, height), buff) == 0)
        return "[rush1-2]";
    if (my_strcmp(rush_function3(length, height), buff) == 0)
        return "[rush1-3]";
    else
        return check_name2(buff, length, height);
}
