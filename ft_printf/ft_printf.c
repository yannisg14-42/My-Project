#include "ft_printf.h"

int ft_handler_specifier(char specifier, va_list *args)
{
    int         i;
    t_dispatch  table[] = {
    {'c', ft_print_char},
    {'s', ft_print_str},
    {'d', ft_print_int},
    {'i', ft_print_int},
    {'u', ft_print_uint},
    {'x', ft_print_hex},
    {'X', ft_print_HEX},
    {'p', ft_print_ptr},
    {'%', ft_print_percent},
    {0, NULL}
    };

    i = 0;
    while (table[i].handler != NULL)
    {
        if ((table[i]).specifier == specifier)
            return (table[i].handler(args));
        i++;
    }
    return (0);
}
int ft_printf(const char *to_print, ...)
{
    int i;
    int count;
    va_list args;

    i = 0;
    count = 0;
    va_start(args, to_print);
    while (to_print[i])
    {
        if (to_print[i] == '%' && to_print[i + 1] != '\0')
        {
            i++;
            count += ft_handler_specifier(to_print[i], &args);
        }
        else
        {
            write(1, &to_print[i], 1);
            count += 1;
        }
        i++;
    }
    va_end(args);
    return (count);
}
