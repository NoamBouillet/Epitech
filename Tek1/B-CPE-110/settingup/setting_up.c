/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** finds the largest square on a map
*/

#include <fcntl.h>
#include "my.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "structs.h"
#include <stdio.h>

int print_biggest_square(char **array_map
    , square_t *tab_square, int ligns, int columns)
{
    int x = tab_square->x_start;
    int y = tab_square->y_start;
    int size = tab_square->size;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            array_map[i][j] = 'x';
        }
    }
    for (int i = 0; i < ligns; i++) {
        write(1, array_map[i], columns + 1);
        write(1, "\n", 1);
        free(array_map[i]);
    }
    free(array_map);
    return 0;
}

int return_columns(char *buffer, int ligns)
{
    int columns = my_len_nbr(ligns) + 1;

    while (buffer[columns] != '\n')
        columns++;
    columns = columns - my_len_nbr(ligns) - 1;
    return columns;
}

char **turns_map_into_array(char *buffer)
{
    int ligns = my_getnbr(buffer, 0);
    int columns = return_columns(buffer, ligns);
    int start = my_len_nbr(ligns) + 1;
    char **array;

    array = malloc(sizeof(char *) * (ligns + 1));
    for (int i = 0; i < ligns; i++) {
        array[i] = malloc(sizeof(char) * (columns + 1));
        for (int j = 0; j < columns; j++) {
            array[i][j] = buffer[start];
            start++;
        }
        array[i][columns] = '\0';
        start++;
    }
    array[ligns] = NULL;
    return array;
}

static int search_square_limits(map_t *map, int x, int y, int size)
{
    if (x + size > map->ligns || y + size > map->columns + 1)
        return 0;
    for (int i = 0; i < size; i++) {
        if (map->array_map[x + size - 1][y + i] == 'o'
            || map->array_map[x + i][y + size - 1] == 'o') {
            return 0;
        }
    }
    return 1;
}

static int add_square(map_t *map, int x, int y, square_t *tab_square)
{
    int size = 1;
    int max_square_size = 0;

    while (search_square_limits(map, x, y, size)) {
        max_square_size = size;
        size++;
    }
    if (max_square_size > tab_square->size) {
        tab_square->x_start = x;
        tab_square->y_start = y;
        tab_square->size = max_square_size;
    }
    return max_square_size;
}

int check_square(map_t *map, int x, int y, square_t *tab_square)
{
    if (map->array_map[x][y] == '.') {
        add_square(map, x, y, tab_square);
    }
    return 0;
}

static int setting_up_operations(char *buffer)
{
    int ligns = my_getnbr(buffer, 0);
    int cols = return_columns(buffer, ligns) - 1;
    square_t tab_square = {0, 0, 0};
    char **array_map = turns_map_into_array(buffer);
    map_t map = {array_map, ligns, cols};

    for (int x = 0; x < map.ligns; x++) {
        for (int y = 0; map.array_map[x][y] != '\0'; y++) {
            check_square(&map, x, y, &tab_square);
        }
    }
    return print_biggest_square(map.array_map
        , &tab_square, map.ligns, map.columns);
}

int setting_up(int ac, char **av)
{
    int fd;
    char *buffer;
    struct stat stats;

    if (ac != 2)
        return error_handling(ac, av);
    fd = open(av[1], O_RDONLY);
    if (fd == -1){
        write(2, "Error, no valid files given\n", 27);
        return 84;
    }
    stat(av[1], &stats);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    buffer[read(fd, buffer, stats.st_size)] = '\0';
    close(fd);
    if (check_buffer(buffer) == 84)
        return 84;
    setting_up_operations(buffer);
    free(buffer);
    return 0;
}
