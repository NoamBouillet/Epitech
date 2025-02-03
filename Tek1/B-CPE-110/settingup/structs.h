/*
** EPITECH PROJECT, 2024
** structs
** File description:
** structs
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
typedef struct squares {
    int x_start;
    int y_start;
    int size;
} square_t;

typedef struct map {
    char **array_map;
    int ligns;   // Number of rows
    int columns; // Number of columns
} map_t;

#endif /* !STRUCTS_H_ */
