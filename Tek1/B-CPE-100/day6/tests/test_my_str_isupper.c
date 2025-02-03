/*
** EPITECH PROJECT, 2024
** test_my_str_isupper
** File description:
** tests it
*/

#include <criterion/criterion.h>
int my_str_islower(char const *str);

Test(my_str_islower, trying_for_normal)
{
    char dest [9] = "BPTNUK";

    int res = my_str_islower(dest);
    cr_assert_eq(res, 1);
}

Test(my_str_islower, negative_response)
{
    char my_dest [10] = "HIl";

    int res = my_str_islower(my_dest);
    cr_assert_eq(res, 0);
}

Test(my_str_islower, results_with_empty_char)
{
    char my_dest [8] = "";

    int res = my_str_islower(my_dest);
    cr_assert_eq(res, 1);
}
