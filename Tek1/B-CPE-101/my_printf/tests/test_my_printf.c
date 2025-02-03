/*
** EPITECH PROJECT, 2024
** test_my_speci
** File description:
** unit tests for specifiers
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, int_specifier, .init = redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, unsigned_int_specifier, .init = redirect_all_std)
{
    my_printf("%u", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, octal_specifier, .init = redirect_all_std)
{
    my_printf("%o", 255);
    cr_assert_stdout_eq_str("377");
}

Test(my_printf, octal_sharp_flag, .init = redirect_all_std)
{
    my_printf("%#o", 255);
    cr_assert_stdout_eq_str("0377");
}

Test(my_printf, int_plus_flag, .init = redirect_all_std)
{
    my_printf("%+d", 255);
    cr_assert_stdout_eq_str("+255");
}

Test(my_printf, unsigned_long_int_specifier, .init = redirect_all_std)
{
    my_printf("%u", -1);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, char_specifier1, .init = redirect_all_std)
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test(my_printf, char_width, .init = redirect_all_std)
{
    my_printf("%4c", 'A');
    cr_assert_stdout_eq_str("   A");
}

Test(my_printf, char_flag_dash, .init = redirect_all_std)
{
    my_printf("%-4c", 'A');
    cr_assert_stdout_eq_str("A   ");
}

Test(my_printf, hex_specifier, .init = redirect_all_std)
{
    my_printf("%x", 2495);
    cr_assert_stdout_eq_str("9bf");
}

Test(my_printf, string_specifier, .init = redirect_all_std)
{
    my_printf("%s", "Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(my_printf, string_width, .init = redirect_all_std)
{
    my_printf("%10s", "Hello");
    cr_assert_stdout_eq_str("     Hello");
}

Test(my_printf, string_flag_dash, .init = redirect_all_std)
{
    my_printf("%-10s", "Hello");
    cr_assert_stdout_eq_str("Hello     ");
}

Test(my_printf, float_specifier, .init = redirect_all_std)
{
    my_printf("%f", 14.84);
    cr_assert_stdout_eq_str("14.840000");
}

Test(my_printf, percent_specifier, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, float_zero_specifier, .init = redirect_all_std)
{
    my_printf("%f", -154.0109999);
    cr_assert_stdout_eq_str("-154.011000");
}

Test(my_printf, float_width_specifier, .init = redirect_all_std)
{
    my_printf("%+15f", 154.000000);
    cr_assert_stdout_eq_str("    +154.000000");
}

Test(my_printf, flag_space_int, .init = redirect_all_std)
{
    my_printf("% d", 154);
    cr_assert_stdout_eq_str(" 154");
}

Test(my_printf, flag_dash_int, .init = redirect_all_std)
{
    my_printf("%-10d", 154);
    cr_assert_stdout_eq_str("154       ");
}

Test(my_printf, exponential_specifier, .init = redirect_all_std)
{
    my_printf("%e", 154.84368);
    cr_assert_stdout_eq_str("1.548437e+02");
}

Test(my_printf, exponential_specifier_inf_zero, .init = redirect_all_std)
{
    my_printf("%e", -0.00000000001238566);
    cr_assert_stdout_eq_str("-1.238566e-11");
}

Test(my_printf, multiple_d, .init = redirect_all_std)
{
    my_printf("%d %d %d", 255, 42, 84);
    cr_assert_stdout_eq_str("255 42 84");
}

Test(my_printf, multiple_specifiers, .init = redirect_all_std)
{
    my_printf("%d %s %e", 255, "bonjour", 255.255);
    cr_assert_stdout_eq_str("255 bonjour 2.552550e+02");
}

Test(my_printf, multiple_specifiers_u_c, .init = redirect_all_std)
{
    my_printf("%u %c", -255, 'c');
    cr_assert_stdout_eq_str("4294967041 c");
}

Test(my_printf, multiple_specifiers_d_and_flag, .init = redirect_all_std)
{
    my_printf("%+10d", 123);
    cr_assert_stdout_eq_str("      +123");
}

Test(my_printf, multiple_specifiers_flag, .init = redirect_all_std)
{
    my_printf("%010d", 123);
    cr_assert_stdout_eq_str("0000000123");
}

Test(my_printf, binary_specifier, .init = redirect_all_std)
{
    my_printf("%b", 5);
    cr_assert_stdout_eq_str("101");
}

Test(my_printf, binary_specifier_NULL, .init = redirect_all_std)
{
    my_printf("%b", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, binary_specifier_negative, .init = redirect_all_std)
{
    my_printf("%b", -2500);
    cr_assert_stdout_eq_str("11111111111111111111011000111100");
}

Test(my_printf, exp_specifier, .init = redirect_all_std)
{
    my_printf("%e", 302.65);
    cr_assert_stdout_eq_str("3.026500e+02");
}

Test(my_printf, longint_modifier, .init = redirect_all_std)
{
    my_printf("%ld", 123456789123456789);
    cr_assert_stdout_eq_str("123456789123456789");
}