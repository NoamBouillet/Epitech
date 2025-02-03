/*
** EPITECH PROJECT, 2024
** error_handling
** File description:
** handles flags errors
*/

#include "../../include/my.h"

int check_flag(flag_properties_t var)
{
    if (var.specifier == 84)
        return 84;
    return 0;
}
