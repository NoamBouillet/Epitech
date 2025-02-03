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

int disp(void *data, char **args)
{
    hardware_t *list_hardware = *((hardware_t **)data);

    if (args[0] != NULL)
        return 84;
    while (list_hardware != NULL) {
        my_printf("%s n°%d - \"%s\"\n",
        list_hardware->type, list_hardware->id, list_hardware->name);
        list_hardware = list_hardware->next;
    }
    return 0;
}
