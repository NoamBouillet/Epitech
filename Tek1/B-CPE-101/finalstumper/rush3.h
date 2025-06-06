/*
** EPITECH PROJECT, 2024
** my
** File description:
** defines all lib functions
*/

#ifndef MY_H
    #define MY_H

//RUSH3

int rush3(char *);
char *rush_function1(int, int);
char *rush_function2(int, int);
char *rush_function3(int, int);
char *rush_function4(int, int);
char *rush_function5(int, int);
char *check_name(char *, int, int);
char *check_name2(char *, int, int);
char *check_name3(char *, int, int);

//Strings

char *my_strcpy(char *, char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
int my_show_word_array(char const **);
int my_strlen(char const *);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
char *my_revstr(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);

//Numbers

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_is_prime(int);
int my_isneg(int);
int my_put_nbr(int);

//Display

void my_putchar(char);
int my_putstr(char const *);
int my_showmem(char const *, int);
int my_showstr(char const *);

//Divers

void my_sort_int_array(int *, int);
void my_swap(int *, int *);

#endif
