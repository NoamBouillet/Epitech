/*
** EPITECH PROJECT, 2025
** check_data_read
** File description:
** checks the data read from the filepath
*/

#include "../include/my_radar.h"

int check_data_read(char **data_read, int status)
{
    int size = 0;

    while (data_read[size] != NULL)
        size++;
    if ((!status && size != 7) || (status && size != 4))
        return 84;
    return 0;
}

int check_data_tower(towers_t *tower)
{
    if (tower->radius == -1 || tower->position.x == -1
        || tower->position.y == -1)
        return 84;
    return 0;
}

int check_data_plane(planes_t *plane)
{
    if (plane->speed == -1 || plane->delay == -1 ||
        plane->current_pos.x == -1 || plane->current_pos.y == -1 ||
        plane->end_position.x == -1 || plane->end_position.y == -1)
        return 84;
    return 0;
}
