/*
** EPITECH PROJECT, 2024
** test_my_strlowcase
** File description:
** tests my_strlowcase
*/

#include <criterion/criterion.h>
char *my_strlowcase(char *str);

Test(my_strlowcase, trying_for_normal)
{
    char dest [9] = "BPTNUK";

    char *res = my_strlowcase(dest);
    cr_assert_str_eq(res, "bptnuk");
}

Test(my_strlowcase, no_changes)
{
    char my_dest [7] = "123456";

    char *res = my_strlowcase(my_dest);
    cr_assert_str_eq(res, "123456");
}
