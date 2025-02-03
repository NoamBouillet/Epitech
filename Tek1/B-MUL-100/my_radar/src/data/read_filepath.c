/*
** EPITECH PROJECT, 2025
** read_filepath
** File description:
** Reads the filepath to extract data
*/

#include "../include/my_radar.h"

void clean_data_read(char **data_read)
{
    for (int i = 0; data_read[i] != NULL; i++) {
        free(data_read[i]);
    }
    free(data_read);
}

int use_line_file(char *line, planes_t **list_planes
    , towers_t **towers, parameters_t params)
{
    char **data_read = my_str_to_word_array(line);

    if (my_strcmp("A", data_read[0]) == 0) {
        if (check_data_read(data_read, 0) == 84)
            return 84;
        *list_planes = add_planes_to_list(*list_planes, params, data_read);
        clean_data_read(data_read);
        return check_data_plane(*list_planes);
    }
    if (my_strcmp("T", data_read[0]) == 0) {
        if (check_data_read(data_read, 1) == 84)
            return 84;
        *towers = add_towers_to_list(*towers, params, data_read);
        clean_data_read(data_read);
        return check_data_tower(*towers);
    }
    clean_data_read(data_read);
    return 84;
}

planes_t *read_list_planes(char *path_to_file,
    parameters_t params, towers_t **towers)
{
    planes_t *list_planes = NULL;
    ssize_t len = 0;
    char *line = NULL;
    FILE *file = fopen(path_to_file, "r");
    size_t len_read = 0;

    if (file == NULL || !params.plane) {
        return (planes_t *)-1;
    }
    do {
        len = getline(&line, &len_read, file);
        if (len == -1)
            break;
        if (use_line_file(line, &list_planes, towers, params) == 84)
            return (planes_t *)-1;
    } while (len != -1);
    fclose(file);
    return list_planes;
}
