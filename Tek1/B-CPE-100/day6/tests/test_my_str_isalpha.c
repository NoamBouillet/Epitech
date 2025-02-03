/*
** EPITECH PROJECT, 2024
** test_my_str_isalpha
** File description:
** checks if a string is only letters
*/

#include <criterion/criterion.h>
int my_str_isalpha(char const *str);

Test(my_str_isalpha, trying_for_normal)
{
    char dest [9] = "bptnuk";

    int res = my_str_isalpha(dest);
    cr_assert_eq(res, 1);
}

Test(my_str_isalpha, negative_response)
{
    char my_dest [10] = "j012hello";

    int res = my_str_isalpha(my_dest);
    cr_assert_eq(res, 0);
}

Test(my_str_isalpha, results_with_empty_char)
{
    char my_dest [8] = "";

    int res = my_str_isalpha(my_dest);
    cr_assert_eq(res, 1);
}
