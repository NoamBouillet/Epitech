/*
** EPITECH PROJECT, 2024
** main
** File description:
** runs the program
*/

#include "my.h"
#include "structs.h"
#include "top_functions.h"

int main(int ac, char **argv)
{
    flags_t flags = {0, 0, 3, 0, -1, 0};

    flags.U_name = "";
    if (search_for_flags(ac, argv, &flags) == 84)
        return 84;
    create_window(flags);
    return 0;
}
