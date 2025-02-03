/*
** EPITECH PROJECT, 2024
** test_my_revstr
** File description:
** tests my_revstr
*/

#include <criterion/criterion.h>
char *my_revstr(char *str);

Test(my_revstr, my_rev_str_reverse_a_string_jmp)
{
    char dest [6] = "bla";

    my_revstr(dest);
    cr_assert_str_eq(dest, "alb");
}

Test(my_revstr, reverse_a_string)
{
    char my_dest [8] = "bloublou";

    my_revstr(my_dest);
    cr_assert_str_eq(my_dest, "uolbuolb");
}
