/*
** EPITECH PROJECT, 2024
** my
** File description:
** defines all lib functions
*/

#include <stddef.h>
#include <stdarg.h>
#include "organized.h"

#ifndef MY_H
    #define MY_H

//Flags_Structs

typedef struct useful_array {
    int length;
    int i;
} cursor_t;

typedef struct var {
    char flag;
    int width;
    int precision;
    char *length;
    char specifier;
} flag_properties_t;

typedef struct pointers_function {
    char specifier;
    int (*function)(flag_properties_t, cursor_t *, va_list);
} function_pointers_t;

//Flags_functions

int check_flag(flag_properties_t);
int error_managing_basics(const char *, va_list);
char *my_length(const char *, cursor_t *);
int my_precision(const char *, cursor_t *);
int my_width(const char *, cursor_t *);
char my_flag(const char *, cursor_t *);
char my_speci(const char *, cursor_t *);
int search_flag(const char *, cursor_t *,
    va_list);
int goes_throught_string(const char *, cursor_t *,
    va_list);
int my_printf(const char *, ...);
void my_flag_gestion(flag_properties_t, cursor_t *, va_list);

//My_Display_Flags

int my_put_power(flag_properties_t, cursor_t *, va_list);
int my_put_nbr(flag_properties_t, cursor_t *, va_list);
int my_put_longint(flag_properties_t, cursor_t *, va_list);
int my_putfloat(flag_properties_t, cursor_t *, va_list);
int my_put_pointer(flag_properties_t, cursor_t *, va_list);
void my_putchar(char c);
int my_put_percent(flag_properties_t, cursor_t *, va_list);
int my_putchar_buffer(flag_properties_t, cursor_t *, va_list);
int my_putstr(flag_properties_t, cursor_t *, va_list);
int my_put_octal(flag_properties_t, cursor_t *, va_list);
int my_put_length(flag_properties_t, cursor_t *, va_list);
int my_put_hexa(flag_properties_t, cursor_t *, va_list);
int my_put_exp(flag_properties_t, cursor_t *, va_list);
int my_put_binary(flag_properties_t, cursor_t *, va_list);
int my_len_longint(unsigned long int);
void display_width(int, flag_properties_t, cursor_t *, int);
void width_left(int, flag_properties_t, cursor_t *, int);
int minimum(int, int);
int maximum(int, int);
void flag_plus(int, flag_properties_t, cursor_t *);
void flag_sharp(flag_properties_t, cursor_t *);
int value_flag(flag_properties_t);

//Lib_if_needed

char *my_strlowcase(char *);
char *my_strcpy(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
int my_show_word_array(char const **);
int my_strlen(char const *str);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
char *my_revstr(char *);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *, char const *);
int my_str_isnum(char const *);
int my_len_nbr(int nb);
int my_compute_power_rec(int nb, int p);

hardware_t *delete_node(hardware_t **begin, int id);
//Numbers

int my_getnbr(char const *str, int position);
int my_isneg(int);
void my_sort_int_array(int *, int);
void my_revlist(hardware_t **begin);

#endif
