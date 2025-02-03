/*
** EPITECH PROJECT, 2024
** main
** File description:
** initializes the cat function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <stddef.h>
#include <unistd.h>

int cat(int ac, char **av);

int main(int ac, char **av)
{
    cat(ac, av);
    return 0;
}
