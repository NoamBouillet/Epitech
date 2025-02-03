/*
** EPITECH PROJECT, 2024
** test_my_strupcase
** File description:
** tests my strupcase
*/

#include <criterion/criterion.h>
char *my_strupcase(char *str);

Test(my_strupcase, trying_for_normal)
{
    char dest [9] = "bptnuk";

    char *res = my_strupcase(dest);
    cr_assert_str_eq(res, "BPTNUK");
}

Test(my_strupcase, no_changes)
{
    char my_dest [7] = "123456";

    char *res = my_strupcase(my_dest);
    cr_assert_str_eq(res, "123456");
}
