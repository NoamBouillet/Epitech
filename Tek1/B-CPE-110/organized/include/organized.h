/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Organized
** File description:
** organized.h
*/

#ifndef ORGANIZED_H
    #define ORGANIZED_H

typedef struct hardware {
    int id;
    char *name;
    char *type;
    struct hardware *next;
} hardware_t;

int error_handling(char **av);
int compare_name(hardware_t *first, hardware_t *second);
int compare_id(hardware_t *first, hardware_t *second);
int compare_type(hardware_t *first, hardware_t *second);

#endif
