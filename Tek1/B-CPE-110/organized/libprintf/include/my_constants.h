/*
** EPITECH PROJECT, 2024
** my_constants
** File description:
** my_constants definition
*/

#ifndef MY_CONSTANTS
    #define MY_CONSTANTS

const char flags_list[] = {'-', '+', '0', ' ', '#'};

const char *length_list[] = {"hh", "h", "ll", "l", "q", "j", "z", "Z", "t" };

const function_pointers_t array_functions[] = {
    { .specifier = 'c', .function = &my_putchar_buffer},
    { .specifier = 'd', .function = &my_put_nbr},
    { .specifier = 'i', .function = &my_put_nbr},
    { .specifier = 'f', .function = &my_putfloat},
    { .specifier = 'F', .function = &my_putfloat},
    { .specifier = 's', .function = &my_putstr},
    { .specifier = 'u', .function = &my_put_longint},
    { .specifier = 'e', .function = &my_put_exp}, //to_do
    { .specifier = 'E', .function = &my_put_exp}, //to_do
    //{ .specifier = 'a', .function = &my_put_double}, //to_do
    { .specifier = 'b', .function = &my_put_binary},
    //{ .specifier = 'g', .function = &my_put_power}, //to_do
    //{ .specifier = 'G', .function = &my_put_power}, //to_do
    { .specifier = 'p', .function = my_put_pointer}, //to_do
    { .specifier = 'n', .function = &my_put_length}, //to_check
    { .specifier = '%', .function = &my_put_percent},
    {.specifier = '\0', .function = NULL}
};

#endif
