/*
** EPITECH PROJECT, 2024
** test_my_str_isprintable
** File description:
** tests my_str_isprintable
*/

#include <criterion/criterion.h>
int my_str_isprintable(char const *str);

Test(my_str_isprintable, trying_for_normal)
{
    char dest [9] = "B5Tn U^";

    int res = my_str_isprintable(dest);
    cr_assert_eq(res, 1);
}

Test(my_str_isprintable, negative_response)
{
    char my_dest [10] = "\n";

    int res = my_str_isprintable(my_dest);
    cr_assert_eq(res, 0);
}

Test(my_str_isprintable, results_with_empty_char)
{
    char my_dest [8] = "";

    int res = my_str_isprintable(my_dest);
    cr_assert_eq(res, 1);
}
