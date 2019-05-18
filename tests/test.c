/*
** EPITECH PROJECT, 2018
** unit_test
** File description:
** test myprintf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void my_printf(char *str, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, another_string_called, .init = redirect_all_std)
{
    my_printf("123");
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, flag_s, .init = redirect_all_std)
{
    my_printf("%s", "test");
    cr_assert_stdout_eq_str("test");
}

Test(my_printf, multi_flags, .init = redirect_all_std)
{
    my_printf("%s%s\n", "test", "test2");
    cr_assert_stdout_eq_str("testtest2\n");
}

Test(my_printf, flag_int, .init = redirect_all_std)
{
    my_printf("%d", 1234);
    cr_assert_stdout_eq_str("1234");
}

Test(my_printf, flag_char, .init = redirect_all_std)
{
    my_printf("%c", 'X');
    cr_assert_stdout_eq_str("X");
}

Test(my_printf, space_in_flag, .init = redirect_all_std)
{
    my_printf("%8s", "four");
    cr_assert_stdout_eq_str("    four");
}

Test(my_printf, ignore_space_flag_string, .init = redirect_all_std)
{
    my_printf("%           s", "ignore");
    cr_assert_stdout_eq_str("ignore");
}

Test(my_printf, space_everywere_flag, .init = redirect_all_std)
{
    my_printf("%        9         s", "trtrtr");
    cr_assert_stdout_eq_str("% 9         s");
}

Test(my_printf, ignore_space_flag_int, .init = redirect_all_std)
{
    my_printf("%        20i", 12345);
    cr_assert_stdout_eq_str("               12345");
}

Test(my_printf, ignore_space_flag_char, .init = redirect_all_std)
{
    my_printf("%        20c", 'T');
    cr_assert_stdout_eq_str("                   T");
}

Test(my_printf, back_slash, .init = redirect_all_std)
{
    my_printf("\\[astek\\]");
    cr_assert_stdout_eq_str("\\[astek\\]");
}

Test(my_printf, back_slash_n, .init = redirect_all_std)
{
    my_printf("\n");
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, tabulation, .init = redirect_all_std)
{
    my_printf("\t");
    cr_assert_stdout_eq_str("\t");
}
