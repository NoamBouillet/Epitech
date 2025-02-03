/*
** EPITECH PROJECT, 2024
** does both
** File description:
** error_managing_and_creating_map
*/

#include "my.h"
#include "structs.h"
#include <stdlib.h>

static int check_lines_buffer(char *buffer, int i, int lines)
{
    int nb_columns = return_columns(buffer, lines);
    int current_columns = 0;
    int real_nbr_lines = 0;

    while (buffer[i] != '\0') {
        while (buffer[i] != '\n') {
            i++;
            current_columns++;
        }
        if (nb_columns != current_columns)
            return 84;
        real_nbr_lines++;
        current_columns = 0;
        i++;
    }
    if (lines != real_nbr_lines)
        return 84;
    return 0;
}

int check_buffer(char *buffer)
{
    int i = 0;
    int ligns = my_getnbr(buffer, 0);

    if (ligns <= 0)
        return 84;
    i = my_len_nbr(ligns) + 1;
    if (check_lines_buffer(buffer, i, ligns) == 84)
        return 84;
    while (buffer[i] != '\0') {
        if (buffer[i] != 'o' && buffer[i] != '.' && buffer[i] != '\n')
            return 84;
        i++;
    }
    return 0;
}

static int find_square_builded_map(char **array_map, int lines)
{
    square_t tab_square = {0, 0, 0};
    map_t map = {array_map, lines, lines -1};

    for (int x = 0; x < map.ligns; x++) {
        for (int y = 0; map.array_map[x][y] != '\0'; y++) {
            check_square(&map, x, y, &tab_square);
        }
    }
    print_biggest_square(map.array_map, &tab_square, map.ligns, map.columns);
    return 0;
}

void change_index(int size, int *index)
{
    if (*index == size)
        *index = 0;
}

int create_map(char **av)
{
    int lines = my_getnbr(av[1], 0);
    char *pattern = av[2];
    int size = my_strlen(pattern);
    int index = 0;
    char **array;

    if (lines <= 0)
        return 84;
    array = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; i < lines; i++) {
        array[i] = malloc(sizeof(char) * (lines + 1));
        for (int j = 0; j < lines; j++) {
            change_index(size, &index);
            array[i][j] = pattern[index];
            index++;
        }
        array[i][lines + 1] = '\0';
    }
    array[lines] = NULL;
    return find_square_builded_map(array, lines);
}

int error_handling(int ac, char **av)
{
    int i = 0;

    if (ac == 3) {
        while (av[2][i] == 'o' || av[2][i] == '.')
            i++;
        if (av[2][i] != '\0' || av[2][0] == '\0')
            return 84;
        return create_map(av);
    }
    return 84;
}
