/*
** EPITECH PROJECT, 2024
** my
** File description:
** defines all lib functions
*/

#include <stddef.h>
#include <stdarg.h>
#include "structs.h"
#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>

#ifndef MY_H
    #define MY_H
    #define HZ sysconf(_SC_CLK_TCK)
    #define PAGE_SIZE sysconf(_SC_PAGESIZE)

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

//Numbers

int my_getnbr(char const *str, int position);
int my_isneg(int);
void my_sort_int_array(int *, int);
processes_t get_files_stats(char *filename);

#endif
