/*
** EPITECH PROJECT, 2024
** test_my_isnum
** File description:
** test my_isnum
*/

#include <criterion/criterion.h>
int my_str_isnum(char const *str);

Test(my_str_isnum, trying_for_normal)
{
    char dest [9] = "123456";

    int res = my_str_isnum(dest);
    cr_assert_eq(res, 1);
}

Test(my_str_isnum, negative_response)
{
    char my_dest [10] = "012hello";

    int res = my_str_isnum(my_dest);
    cr_assert_eq(res, 0);
}

Test(my_str_isnum, results_with_empty_char)
{
    char my_dest [8] = "";

    int res = my_str_isnum(my_dest);
    cr_assert_eq(res, 1);
}
