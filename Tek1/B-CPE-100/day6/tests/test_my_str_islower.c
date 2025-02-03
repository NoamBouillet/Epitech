/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** checks if a string contains only lower alphabet letters
*/

#include <criterion/criterion.h>
int my_str_islower(char const *str);

Test(my_str_islower, trying_for_normal)
{
    char dest [9] = "bptnuk";

    int res = my_str_islower(dest);
    cr_assert_eq(res, 1);
}

Test(my_str_islower, negative_response)
{
    char my_dest [10] = "jOhello";

    int res = my_str_islower(my_dest);
    cr_assert_eq(res, 0);
}

Test(my_str_islower, results_with_empty_char)
{
    char my_dest [8] = "";

    int res = my_str_islower(my_dest);
    cr_assert_eq(res, 1);
}
