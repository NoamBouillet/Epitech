/*
** EPITECH PROJECT, 2024
** main
** File description:
** sorts the arguments of the main by ascii order
*/

#include <string.h>

int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

void swap(char **arr, int j)
{
    char *temp = arr[j];

    arr[j] = arr[j + 1];
    arr[j + 1] = temp;
}

int cmp_and_swap(char **arr, int j)
{
    if (my_strcmp(arr[j], arr[j + 1]) > 0) {
        swap(arr, j);
        return 1;
    }
    return 0;
}

void my_operations_char_array(char **arr, int n)
{
    int my_swap;

    for (int i = 0; i < n - 1; i++) {
        my_swap = 0;
        for (int j = 0; j < n - i - 1; j++) {
            my_swap = cmp_and_swap(arr, j);
        }
        if (!my_swap) {
            break;
        }
    }
}

int main(int argc, char **argv)
{
    my_operations_char_array(argv, argc);
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
    return 0;
}
