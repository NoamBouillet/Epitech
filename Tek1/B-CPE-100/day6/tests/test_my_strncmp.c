/*
** EPITECH PROJECT, 2024
** test of my_strncmp
** File description:
** tests it 
*/

#include <criterion/criterion.h>
int my_strncmp(char *s1, char const *s2, int n);

Test(my_strncmp, trying_for_equal_with_more_characters)
{
  char dest [9] = "tnuk";
  char test [10] = "tnu";

  int res = my_strncmp(dest, test, 3);
  cr_assert_eq(res, 1);
}

Test(my_strncmp, trying_for_negative_with_less_characters)
{
    char my_dest [10] = "a";
    char test[10] = "b";

    int res = my_strncmp(my_dest, test, 2);
    cr_assert_eq(res, -1);
}

Test(my_strncmp, trying_for_equal_with_0_characters)
{
    char my_dest [10] = "blabla";
    char test[10] = "teub";

    int res = my_strncmp(my_dest, test, 0);
    cr_assert_eq(res, 0);
}

Test(my_strncmp, trying_for_positive_again)
{
    char my_dest [10] = "b";
    char test[10] = "a";

    int res = my_strncmp(my_dest, test, 2);
    cr_assert_eq(res, 1);
}
