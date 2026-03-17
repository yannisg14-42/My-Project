#include "ft_printf.h"

int ft_print_uint(va_list *args)
{
    int             count;
    unsigned int    nb;

    nb = va_arg(*args, unsigned int);
    count = 0;
    if (nb == 0)
    {
        write(1, "0", 1);
        return (1);
    }
        count += ft_print_digits((long)nb);
    return (count);  
}
int ft_print_hex_digits(unsigned long nb, char *base)
{
    char    c;
    int     count;
    
    c = base[nb % 16];
    count = 1;
    if (nb >= 16)
        count = ft_print_hex_digits(nb / 16, base) + 1;
    write(1, &c, 1);
    return (count);
}
int ft_print_hex(va_list *args)
{
    unsigned int    nb;
    int             count;

    nb = va_arg(*args, unsigned int);
    count = 0;
    if (nb == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    count += ft_print_hex_digits((unsigned long)nb, "0123456789abcdef");
    return (count);
}
int ft_print_HEX(va_list *args)
{
    unsigned int    nb;
    int             count;

    nb = va_arg(*args, unsigned int);
    count = 0;
    if (nb == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    count += ft_print_hex_digits((unsigned long)nb, "0123456789ABCDEF");
    return (count);
}
int ft_print_ptr(va_list *args)
{
    void    *ptr;
    int     count;

    ptr = va_arg(*args, void *);
    count = 0;
    if (ptr == NULL)
    {
        write(1, "0x0", 3);
        return (3);
    }
    write(1, "0x", 2);
    count += 2;
    count += ft_print_hex_digits((unsigned long)ptr, "0123456789abcdef");
    return (count);
}
