/*
** EPITECH PROJECT, 2025
** secured
** File description:
** functions
*/

#include "../hashtable.h"
#include <string.h>

int hash(char *key, __attribute__((unused)) int len)
{
    uint32_t hash = 0x811c9dc5;
    uint32_t prime = 0x01000193;
    int i = 0;

    if (!key)
        return 0;
    while (*key) {
        hash ^= (uint32_t)(*key + (i * prime));
        hash = (hash << 7) | (hash >> 25);
        hash *= prime;
        hash ^= (hash >> 17);
        key++;
        i++;
    }
    return (int)(hash & 0x7FFFFFFF);
}

void delete_hashtable(hashtable_t *ht)
{
    slots_t *current = NULL;
    slots_t *temp = NULL;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        current = ht->slots[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp->value);
            free(temp);
        }
    }
    free(ht->slots);
    ht->size = -1;
    free(ht);
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *new_hashtable = malloc(sizeof(hashtable_t));
    slots_t **slots = NULL;

    if (!new_hashtable || len <= 0 || hash == NULL)
        return NULL;
    slots = malloc(sizeof(slots_t *) * len);
    if (!slots)
        return NULL;
    for (int i = 0; i < len; i++) {
        slots[i] = NULL;
    }
    new_hashtable->slots = slots;
    new_hashtable->hash = hash;
    new_hashtable->size = len;
    return new_hashtable;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int to_assign = 0;
    slots_t *new_slot = malloc(sizeof(slots_t));
    slots_t *list = NULL;

    if (!ht || ht->size == -1 || !key || !value || !new_slot || !ht->hash)
        return 84;
    to_assign = ht->hash(key, ht->size);
    list = ht->slots[to_assign % ht->size];
    for (; list != NULL; list = list->next) {
        if (ht_replace(list, to_assign, value)) {
            free(new_slot);
            return 0;
        }
    }
    new_slot->key = to_assign;
    new_slot->value = my_strdup(value);
    new_slot->next = ht->slots[to_assign % ht->size];
    ht->slots[to_assign % ht->size] = new_slot;
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    int size = 0;

    if (ht == NULL || ht->size == -1)
        return;
    size = ht->size;
    for (int i = 0; i < size; i++) {
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:\n");
        for (slots_t *slots_to_show = ht->slots[i];
            slots_to_show != NULL; slots_to_show = slots_to_show->next) {
            my_putstr("> ");
            my_put_nbr(slots_to_show->key);
            my_putstr(" - ");
            my_putstr(slots_to_show->value);
            my_putchar('\n');
        }
    }
}
