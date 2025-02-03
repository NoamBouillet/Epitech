/*
** EPITECH PROJECT, 2024
** test_my_str_capitalize
** File description:
** tests it
*/

#include <criterion/criterion.h>
char *my_strcapitalize(char *str);

Test(my_strcapitalize, trying_for_normal)
{
    char dest [20] = "this is a tEST";

    char *res = my_strcapitalize(dest);
    cr_assert_str_eq(res, "This Is A Test");
}

Test(my_strcapitalize, no_changes)
{
    char my_dest [20] = "likingblabla";

    char *res = my_strcapitalize(my_dest);
    cr_assert_str_eq(res, "Likingblabla");
}

Test(my_strcapitalize, no_changes3)
{
    char my_dest [20] = "this-is-a-test-2";

    char *res = my_strcapitalize(my_dest);
    cr_assert_str_eq(res, "This-Is-A-Test-2");
}
