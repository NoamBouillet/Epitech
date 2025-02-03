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

int main(void)
{
    hardware_t *list_hardware = NULL;
    hardware_t *tmp = NULL;
    int exit_value = 0;

    if (workshop_shell(&list_hardware) == 84) {
        exit_value = 84;
    }
    while (list_hardware != NULL) {
        tmp = list_hardware->next;
        free(list_hardware);
        list_hardware = tmp;
    }
    return exit_value;
}
