/*
** EPITECH PROJECT, 2024
** mylist
** File description:
** defines a list
*/

#ifndef MY_LIST
    #define MY_LIST

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

int my_list_size(linked_list_t const *begin);
void my_rev_list(linked_list_t **begin);
linked_list_t *my_params_to_list(int ac, char *const *av);
int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
    void const *data_ref, int (*cmp)());
int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *));
linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref
    , int (*cmp)());
int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)());
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
int my_sort_list(linked_list_t **begin, int (*cmp)());
int my_sort_list(linked_list_t **begin, int (*cmp)());
#endif
