/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** tests it
*/

#include <criterion/criterion.h>
int my_strcmp(char *s1, char const *s2);

Test(my_strcmp, trying_for_equal)
{
  char dest [9] = "bbbe";
  char test [5] = "bbb";

  int res = my_strcmp(dest, test);
  cr_assert_eq(res, 1);
}

Test(my_strcmp, trying_for_negative)
{
    char my_dest [10] = "abcde";
    char test[10] = "bcdef";

    int res = my_strcmp(my_dest, test);
    cr_assert_eq(res, -1);
}

Test(my_strcmp, trying_for_positive)
{
    char my_dest [10] = "bcde";
    char test[10] = "abcd";

    int res = my_strcmp(my_dest, test);
    cr_assert_eq(res, 1);
}
