/*
** EPITECH PROJECT, 2024
** test_my_strncpy
** File description:
** tests my_strncpy
*/

#include <criterion/criterion.h>
char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest [12] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_string_in_empty_array)
{
    char dest [12] = {0};

    my_strncpy(dest, "HelloWorld", 0) ;
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, string_in_empty_array)
{
    char dest [120] = {0};

    my_strncpy(dest, "HelloWorld", 120) ;
    cr_assert_str_eq(dest, "HelloWorld");
}

Test(my_strncpy, trying_with_a_full_char)
{
    char dest [61] = "AAAAAA";

    my_strncpy(dest, "Hello", 5) ;
    cr_assert_str_eq(dest, "HelloA");
}

