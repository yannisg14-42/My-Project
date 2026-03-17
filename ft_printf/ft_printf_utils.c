#include "ft_printf.h"

int ft_print_char(va_list *args)
{
    char    c;

    c = va_arg(*args, int);
    write(1, &c, 1);
    return (1);
}
int ft_print_percent(va_list *args)
{
    (void)args;
    write(1, "%", 1);
    return (1);
}
int ft_print_str(va_list *args)
{
    char    *str;
    int     len;

    str = va_arg(*args, char *);
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
    len = (int)ft_strlen(str);
    write(1, str, len);
    return (len);
}
int ft_print_digits(long nb)
{
    char    c;
    int     count;

    c = nb % 10 + '0';
    count = 1;
    if (nb >= 10)
        count = ft_print_digits(nb / 10) + 1;
    write(1, &c, 1);
    return (count);
}
int ft_print_int(va_list *args)
{
    long    nb;
    int     count;

    nb = (long)va_arg(*args, int);
    count = 0;
    if (nb == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    if (nb < 0)
    {
        write(1, "-", 1);
        count++;
        nb *= -1;
    }
        count += ft_print_digits(nb);
    return (count);
}
