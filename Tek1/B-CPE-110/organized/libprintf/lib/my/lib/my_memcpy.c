/*
** EPITECH PROJECT, 2024
** my_memcpy
** File description:
** duplicates bytes
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
