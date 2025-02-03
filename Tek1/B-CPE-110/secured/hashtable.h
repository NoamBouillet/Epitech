/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H
    #include <stdint.h>
    #include <stddef.h>
    #include <stdio.h>
    #include "unistd.h"
    #include <stdlib.h>

typedef struct slots {
    int key;
    char *value;
    struct slots *next;
} slots_t;

typedef struct hashtable_s {
    slots_t **slots;
    int (*hash)(char *, int);
    int size;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int ht_replace(slots_t *slot, int to_assign, char *value);
char *my_strdup(char const *src);

//LIB

int my_put_nbr(int nbr);
int my_putstr(char *str);
void my_putchar(char c);

#endif /* HASHTABLE_H */
