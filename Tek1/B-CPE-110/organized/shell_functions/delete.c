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

void delete_node_chosen(hardware_t **previous
    , hardware_t **begin, hardware_t **current)
{
    hardware_t *to_free = *current;

    if (*previous == NULL) {
        *begin = to_free->next;
        *current = *begin;
    } else {
        (*previous)->next = to_free->next;
        *current = to_free->next;
    }
    free(to_free);
}

hardware_t *delete_node(hardware_t **begin, int id)
{
    hardware_t *current = *begin;
    hardware_t *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            my_printf("%s n°%d - \"%s\" deleted.\n",
                current->type, current->id, current->name);
            delete_node_chosen(&previous, begin, &current);
            return *begin;
        } else {
            previous = current;
            current = current->next;
        }
    }
    return (hardware_t *)-1;
}

int str_to_num(char *str)
{
    int value = 0;

    if (str[0] == '0' && my_strlen(str) == 1)
        return value;
    value = my_getnbr(str, 0);
    if (value == 0)
        return -1;
    return value;
}

int *get_id_to_delete(int count, char **args)
{
    int *fields = malloc(count * sizeof(int));

    if (!fields)
        return NULL;
    for (int i = 0; i < count; i++) {
        fields[i] = str_to_num(args[i]);
        if (fields[i] < 0) {
            free(fields);
            return NULL;
        }
    }
    return fields;
}

int del(void *data, char **args)
{
    int *fields;
    int count = 0;
    hardware_t *list_hardware = *((hardware_t **)data);

    if (args == NULL || args[0] == NULL)
        return 84;
    while (args[count] != NULL)
        count++;
    fields = get_id_to_delete(count, args);
    if (fields == NULL)
        return 84;
    for (int i = 0; i < count; i++) {
        list_hardware = delete_node(&list_hardware, fields[i]);
        if (list_hardware == (hardware_t *)-1)
            return 84;
    }
    *((hardware_t **)data) = list_hardware;
    free(fields);
    return 0;
}
