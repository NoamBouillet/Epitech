/*
** EPITECH PROJECT, 2024
** my_rev_list
** File description:
** reverses the order of the list's elements
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include "my.h"
#include "organized.h"
#include "shell.h"

void my_revlist(hardware_t **begin)
{
    hardware_t *last = NULL;
    hardware_t *actual_element = *begin;
    hardware_t *next = NULL;

    while (actual_element != NULL) {
        next = actual_element->next;
        actual_element->next = last;
        last = actual_element;
        actual_element = next;
    }
    *begin = last;
}
