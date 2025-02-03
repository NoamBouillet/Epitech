/*
** EPITECH PROJECT, 2024
** cat
** File description:
** cat
*/

#include <fcntl.h>
#include "my.h"
#include <stddef.h>
#include <unistd.h>

int my_cat_operations(int fd, char *buffer, int argc, char **argv)
{
    int size = 0;
    int problem = 0;

    for (int i = 1; i < argc; i++){
        fd = open(argv[i], O_RDONLY);
        if (fd == -1){
            write(2, "cat", 4);
            write(2, argv[i], my_strlen(argv[i]));
            write(2, ": Error, no valid files given\n", 29);
            problem = 1;
        }
        size = read(fd, buffer, 30000);
        buffer[size] = '\0';
        write(1, buffer, size);
        close(fd);
    }
    if (problem == 1)
        return 84;
    return 0;
}

int cat(int ac, char **av)
{
    int fd;
    char buffer[30000];

    if (ac == 1){
        if (read(fd, buffer, 30000) != 0) {
            my_putstr(buffer);
            cat(ac, av);
        }
    }
    if (my_cat_operations(fd, buffer, ac, av) == 84)
        return 84;
    return 0;
}
