/*
** EPITECH PROJECT, 2024
** my_flag_gestion
** File description:
** displays everything about a flag
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_constants.h"

void my_flag_gestion(flag_properties_t var,
    cursor_t *cursor, va_list list_arguments)
{
    int i = 0;

    while (array_functions[i].specifier != '\0') {
        if (array_functions[i].specifier == var.specifier)
            array_functions[i].function(var, cursor, list_arguments);
        i++;
    }
}
