/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** reproduce the strstr function
*/

#include <criterion/criterion.h>
char *my_strstr(char *str, char const *to_find);

Test(my_strstr, trying_for_normal)
{
    char dest [9] = "bptnuk";
    char test [5] = "tnuk";

    char *res = my_strstr(dest, test);
    cr_assert_str_eq(res, "tnuk");
}

Test(my_strstr, no_results)
{
    char my_dest [7] = "testtwo";
    char test [1] = "m";

    char *res = my_strstr(my_dest, test);
    cr_assert_null(res);
}

Test(my_strstr, no_results_with_empty_char)
{
    char my_dest [0] = "";
    char test[1] = "m";

    char *res = my_strstr(my_dest, test);
    cr_assert_null(res);
}
