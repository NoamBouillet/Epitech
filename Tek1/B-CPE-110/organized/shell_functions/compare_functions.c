/*
** EPITECH PROJECT, 2024
** Organized
** File description:
** organized
*/

#include "organized.h"
#include "my.h"
#include <stdint.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>
#include <string.h>

int compare_id(hardware_t *first, hardware_t *second)
{
    return first->id - second->id;
}

int compare_name(hardware_t *first, hardware_t *second)
{
    return my_strcmp(first->name, second->name);
}

int compare_type(hardware_t *first, hardware_t *second)
{
    return my_strcmp(first->type, second->type);
}
