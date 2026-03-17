#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    // %c
    ft_printf("char: %c\n", 'A');
    printf("char: %c\n", 'A');

    // %s
    ft_printf("str: %s\n", "hello");
    ft_printf("null str: %s\n", NULL);
    printf("null str: %s\n", NULL);

    // %d and %i edge cases
    ft_printf("zero: %d\n", 0);
    ft_printf("negative: %d\n", -42);
    ft_printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MIN: %d\n", INT_MIN);

    // %u
    ft_printf("uint: %u\n", 4294967295u);
    printf("uint: %u\n", 4294967295u);

    // %x and %X
    ft_printf("hex: %x\n", 255);
    ft_printf("HEX: %X\n", 255);
    printf("hex: %x\n", 255);

    // %p
    int n = 42;
    ft_printf("ptr: %p\n", &n);
    printf("ptr: %p\n", &n);
    ft_printf("null ptr: %p\n", NULL);
    printf("null ptr: %p\n", NULL);

    // %%
    ft_printf("percent: 100%%\n");
    printf("percent: 100%%\n");

    // return value check
    int r1 = ft_printf("hello %d\n", 42);
    int r2 = printf("hello %d\n", 42);
    ft_printf("ft_printf returned: %d\n", r1);
    ft_printf("printf returned: %d\n", r2);
    return (0);
}
