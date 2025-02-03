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

static int check_type(char **av)
{
    for (int type = 0; av[type] != NULL && av[type + 1] != NULL; type += 2) {
        if (my_strcmp(av[type], "WIRE") == 0)
            return 0;
        if (my_strcmp(av[type], "DEVICE") == 0)
            return 0;
        if (my_strcmp(av[type], "PROCESSOR") == 0)
            return 0;
        if (my_strcmp(av[type], "SENSOR") == 0)
            return 0;
        if (my_strcmp(av[type], "ACTUATOR") == 0)
            return 0;
    }
    return 84;
}

int error_handling(char **av)
{
    int count = 0;

    while (av[count] != NULL)
        count++;
    if (check_type(av) == 84)
        return 84;
    if (count % 2 == 1)
        return 84;
    return 0;
}

int get_biggest_id(hardware_t *head_hardware)
{
    int biggest_id = 0;

    while (head_hardware != NULL) {
        if (head_hardware->id > biggest_id)
            biggest_id = head_hardware->id;
        head_hardware = head_hardware->next;
    }
    return biggest_id + 1;
}

int add_to_list(void *data, char *name, char *type)
{
    hardware_t *list_hardware = *((hardware_t **)data);
    hardware_t *new_instance = malloc(sizeof(hardware_t));
    static int biggest_id = 0;

    if (!new_instance || !name || !type)
        return 84;
    new_instance->id = biggest_id;
    new_instance->name = my_strdup(type);
    new_instance->type = my_strdup(name);
    new_instance->next = list_hardware;
    *(hardware_t **)data = new_instance;
    my_printf("%s n°%d - \"%s\" added.\n",
    new_instance->type, new_instance->id, new_instance->name);
    biggest_id++;
    return 0;
}

int add(void *data, char **args)
{
    if (error_handling(args) == 84)
        return 84;
    for (int i = 0; args[i] != NULL; i += 2) {
        add_to_list(data, args[i], args[i + 1]);
    }
    return 0;
}
