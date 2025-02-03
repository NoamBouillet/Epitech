/*
** EPITECH PROJECT, 2025
** secured
** File description:
** search and delete
*/

#include "../hashtable.h"

slots_t *delete_node(slots_t **previous_sprite
    , slots_t **begin, slots_t **current_sprite)
{
    slots_t *to_free = *current_sprite;

    if (*previous_sprite == NULL) {
        *begin = to_free->next;
        *current_sprite = *begin;
        free(to_free->value);
        free(to_free);
        return *begin;
    } else {
        (*previous_sprite)->next = to_free->next;
        *current_sprite = to_free->next;
    }
    free(to_free->value);
    free(to_free);
    return *begin;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int modulo = 0;
    slots_t *begin = NULL;
    slots_t *previous = NULL;

    if (!ht || ht->size == -1 || !key || !ht->hash)
        return 84;
    hashed = ht->hash(key, ht->size);
    modulo = hashed % ht->size;
    begin = ht->slots[modulo];
    for (slots_t *current = ht->slots[modulo];
        current != NULL; current = current->next) {
        if (current->key == hashed) {
            ht->slots[modulo] = delete_node(&previous, &begin, &current);
            return 0;
        }
        previous = current;
    }
    return 84;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed = 0;
    int modulo = 0;

    if (!ht || ht->size == -1 || !key || !ht->hash)
        return NULL;
    hashed = ht->hash(key, ht->size);
    modulo = hashed % ht->size;
    for (slots_t *slots_to_show = ht->slots[modulo];
        slots_to_show != NULL; slots_to_show = slots_to_show->next) {
        if (slots_to_show->key == hashed)
            return slots_to_show->value;
    }
    return NULL;
}

int ht_replace(slots_t *slot, int to_assign, char *value)
{
    if (slot->key == to_assign) {
        free(slot->value);
        slot->value = my_strdup(value);
        return 1;
    }
    return 0;
}
