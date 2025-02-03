/*
** EPITECH PROJECT, 2024
** pong
** File description:
** pong motion
*/

#include <math.h>
#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static int error_handling(char **argv, int ac)
{
    float check_multiplier = (float)strtof(argv[7], NULL);
    int multiplier = (int)strtol(argv[7], NULL, 10);
    char *badstring;
    char *endptr;

    for (int i = 1; i < ac; i++) {
        badstring = argv[i];
        endptr = NULL;
        strtof(badstring, &endptr);
        if (strcmp(endptr, badstring) == 0) {
            return 84;
        }
    }
    if (check_multiplier != multiplier)
        return 84;
    if (multiplier < 0)
        return 84;
    return 0;
}

coord_t displays_vector(char **argv, coord_t before, coord_t now)
{
    coord_t vector;

    vector.x = now.x - before.x;
    vector.y = now.y - before.y;
    vector.z = now.z - before.z;
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n"
        , vector.x, vector.y, vector.z);
    return vector;
}

static coord_t find_coordinates(coord_t now, coord_t vector)
{
    coord_t coord_to_paddle;
    double multiplier = now.z / vector.z;

    if (multiplier < 0)
        multiplier = multiplier * -1;
    coord_to_paddle.z = 0;
    coord_to_paddle.x = now.x + vector.x * multiplier;
    coord_to_paddle.y = now.y + vector.y * multiplier;
    return coord_to_paddle;
}

static double norm_vector(coord_t start, coord_t end)
{
    double norm = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2)
        + pow((end.z - start.z), 2));

    return norm;
}

int displays_coordinates(char **argv, coord_t coord_now, coord_t vector)
{
    int multiplier = (int)strtol(argv[7], NULL, 10);
    float first_coord = coord_now.x + vector.x * multiplier;
    float second_coord = coord_now.y + vector.y * multiplier;
    float third_coord = coord_now.z + vector.z * multiplier;

    printf("At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n"
        , multiplier, first_coord, second_coord, third_coord);
    return 0;
}

int displays_angle(coord_t vector, coord_t now)
{
    double incidence;
    double norm;

    if (now.z == 0 && vector.z == 0) {
        printf("The incidence angle is:\n0.00 degrees\n");
        return 0;
    }
    if (now.z * vector.z < 0) {
        norm = norm_vector(now, find_coordinates(now, vector));
        if (norm == 0)
            return 84;
        incidence = absolute_value(asin(now.z / norm) * (180 / PI));
        printf("The incidence angle is:\n%.2f degrees\n", incidence);
        return 0;
    }
    printf("The ball won't reach the paddle.\n");
    return 0;
}

int displays_pong(int argc, char **argv)
{
    coord_t coord_before;
    coord_t coord_now;
    coord_t vector;

    coord_before.x = strtof(argv[1], NULL);
    coord_before.y = strtof(argv[2], NULL);
    coord_before.z = strtof(argv[3], NULL);
    coord_now.x = strtof(argv[4], NULL);
    coord_now.y = strtof(argv[5], NULL);
    coord_now.z = strtof(argv[6], NULL);
    vector = displays_vector(argv, coord_before, coord_now);
    if (displays_coordinates(argv, coord_now, vector) == 84)
        return 84;
    if (displays_angle(vector, coord_now) == 84)
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 8)
        return 84;
    if (error_handling(argv, argc) == 84)
        return 84;
    displays_pong(argc, argv);
    return 0;
}
